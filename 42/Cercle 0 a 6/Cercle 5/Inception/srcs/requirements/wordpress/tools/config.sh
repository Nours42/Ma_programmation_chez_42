sleep 20
wp config create	--allow-root \
					--dbname=$SQL_DATABASE \
					--dbuser=$SQL_USER \
					--dbpass=$SQL_PASSWORD \
					--dbhost=mariadb:3306 --path='/var/www/wordpress'
wp core install 

#!/bin/bash

##############################
### GLOBAL CONSTANT ###
SEP_P="####################"
SEP_SP="--------------------"

##############################
### COLOR CONSTANT ###
RD='\033[0;31m'
GN='\033[0;32m'
YE='\033[0;33m'
BU='\033[0;34m'
MG='\033[0;35m'
NC='\033[0m'

##############################
### GLOBAL VARIABLE ###
PROGRAM=${0}

##############################
### FUNCTIONS ###





function	check_wp_config()
{
	echo -e "${YE}${SEP_SP}${NC}";
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	# CHECK IF THE WORDPRESS CONFIG FILE EXISTS
	if ! [[ -e "${WP_DIR}/${WP_CFG}" ]];
	then
		echo -e "${RD}Warning: ${WP_DB} does not exist${NC}";
		return 1;
	fi;
	return 0;
}

# CREATE wp-config.php IF NOT EXISTS
function	create_wp_config()
{
	echo -e "${YE}${SEP_SP}${NC}";
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	wp config create --allow-root --path=${WP_DIR} --dbname=${WP_DB} --dbuser=${WP_USR_NAME} --dbpass=${WP_USR_PASSWORD} --locale=fr_FR --dbhost=${WP_DB_HOST}:${WP_DB_HOST_PORT};
	if [ "$?" != 0 ]; then return 1; fi;
	wp config set --allow-root --path=${WP_DIR} --raw WP_DEBUG true;
	if [ "$?" != 0 ]; then return 1; fi;
	wp config set --allow-root --path=${WP_DIR} ABSPATH ${WP_DIR};
	if [ "$?" != 0 ]; then return 1; fi;
	return 0;
}

# CHANGE wp-config.php SETTINGS ACCORDING TO ENV
function	set_wp_config()
{
	echo -e "${YE}${SEP_SP}${NC}";
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	# SET DATABASE NAME
	wp config set --allow-root --path=${WP_DIR} DB_NAME ${WP_DB}
	if [ "$?" != 0 ]; then return 1; fi;
	wp config set --allow-root --path=${WP_DIR} DB_USER ${WP_USR_NAME}
	if [ "$?" != 0 ]; then return 1; fi;
	wp config set --allow-root --path=${WP_DIR} DB_PASSWORD ${WP_USR_PASSWORD}
	if [ "$?" != 0 ]; then return 1; fi;
	wp config set --allow-root --path=${WP_DIR} DB_HOST ${WP_DB_HOST}
	if [ "$?" != 0 ]; then return 1; fi;
	return 0;
}

function	create_wp_db()
{
	echo -e "${YE}${SEP_SP}${NC}";
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	wp core install --allow-root --path=${WP_DIR} --url=${DOMAIN_NAME} --title=${WP_TITLE} --admin_user=${WP_MANAGER_NAME} --admin_password=${WP_MANAGER_PASSWORD} --admin_email=${WP_MANAGER_EMAIL} --skip-email
	if [ "$?" != 0 ];
	then
		echo -e "${RD}Error: wordpress create database${NC}";
		echo -e "${YE}${SEP_SP}${NC}";
		return 1;
	fi;
	return 0;
}

function	create_wp_db_user()
{
	echo -e "${YE}${SEP_SP}${NC}";
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	wp user create --allow-root --path=${WP_DIR} ${WP_USR_NAME} ${WP_USR_EMAIL} --user_pass=${WP_USR_PASSWORD} --display_name=${WP_USR_DISP_NAME} --role=author
	if [ "$?" != 0 ];
	then
		echo -e "${RD}Error: wordpress create user${NC}";
		echo -e "${YE}${SEP_SP}${NC}";
		return 1;
	fi;
	return 0;
}

function	start_php_fpm()
{
	echo -e "${YE}${SEP_SP}${NC}";
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	# EXECUTE PHP-FPM WITH --nodaemonize TO BE DETACHED OF THE DAEMON PID
	exec /usr/sbin/php-fpm7.3 --nodaemonize;
	if [ "$?" != 0 ];
	then
		echo -e "${RD}Error: start php-fpm${NC}";
		echo -e "${YE}${SEP_SP}${NC}";
		return 1;
	fi;
	return 0;
}

function	main()
{
	echo -e "${YE}${SEP_SP}${NC}";
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	# CHECK WORDPRESS SETUP
	sleep 10
	check_wp_config;
	if [ "$?" != 0 ]
	then
		create_wp_config;
		if [ "$?" != 0 ]; then return 1; fi;
	else
		set_wp_config;
		if [ "$?" != 0 ]; then return 1; fi;
	fi;
	# INSTALL WORDPRESS ONLY IF IT IS NOT ALREADY INSTALLED
	wp core is-installed --allow-root --path=${WP_DIR};
	if [ "$?" == 1 ]
	then
		# WORDPRESS DATABASE SETUP
		create_wp_db;
		if [ "$?" != 0 ]; then return 1; fi;
		# WORDPRESS DATABASE SETUP
		create_wp_db_user;
		if [ "$?" != 0 ]; then return 1; fi;
	else
		echo -e "${GN}Wordpress is already installed${NC}";
	fi;
	# START PHP-FPM SERVICE
	start_php_fpm;
	if [ "$?" != 0 ]; then return 1; fi;
	return 0;
}

##############################
### PROGRAM START ###
clear;
echo -e "${YE}${SEP_SP}${NC}";
echo -e "${YE}Program \"${PROGRAM}\"${NC}"
main
exit $?;
### PROGRAM END ###