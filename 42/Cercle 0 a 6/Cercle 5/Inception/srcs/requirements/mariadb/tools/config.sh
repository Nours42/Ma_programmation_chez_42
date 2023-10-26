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
function	start_mysql()
{
	echo -e "${YE}${SEP_SP}${NC}";
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	service mariadb start;
	if [ "$?" != 0 ];
	then
		echo -e "${RD}Error: start mysql${NC}";
		echo -e "${YE}${SEP_SP}${NC}";
		return 1;
	fi;
	return 0;
}

function	stop_mysql()
{
	echo -e "${YE}${SEP_SP}${NC}";
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	mysqladmin -u root -p${MYSQL_ROOT_PASSWORD} shutdown;
	if [ "$?" != 0 ];
	then
		echo -e "${RD}Error: stop mysql${NC}";
		echo -e "${YE}${SEP_SP}${NC}";
		return 1;
	fi;
	return 0;
}

function	check_mysql_wp_setup()
{
	echo -e "${YE}${SEP_SP}${NC}";
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	# CHECK IF THE WORDPRESS DATABASE EXISTS
	if ! [[ -e "${MYSQL_DATA}/${WP_DB}" ]];
	then
		echo -e "${RD}Warning: ${WP_DB} does not exist${NC}";
		return 1;
	fi;
	return 0;
}

function	exec_mysql_secure_install()
{
	echo -e "${YE}${SEP_SP}${NC}";
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	local SECURE_MYSQL=$(expect -c "
		set timeout 10
		spawn mysql_secure_installation
		expect \"Enter current password for root (enter for none):\"
		send \"${MYSQL_ROOT_PASSWORD}\r\"
		expect \"Change the root password?\"
		send \"y\r\"
		expect \"New password:\"
		send \"${MYSQL_ROOT_PASSWORD}\r\"
		expect \"Re-enter new password:\"
		send \"${MYSQL_ROOT_PASSWORD}\r\"
		expect \"Remove anonymous users?\"
		send \"y\r\"
		expect \"Disallow root login remotely?\"
		send \"y\r\"
		expect \"Remove test database and access to it?\"
		send \"y\r\"
		expect \"Reload privilege tables now?\"
		send \"y\r\"
		expect eof
	");
	if [ "$?" != 0 ];
	then
		echo -e "${RD}Error: mysql_secure_installation${NC}";
		echo -e "${YE}${SEP_SP}${NC}";
		return 1;
	fi;
	echo "$SECURE_MYSQL";
	return 0;
}

function	create_wp_db()
{
	echo -e "${YE}${SEP_SP}${NC}";
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	mysql -u root -p${MYSQL_ROOT_PASSWORD} -v -e "CREATE DATABASE IF NOT EXISTS ${WP_DB};";
#	mysql -u root -p${MYSQL_ROOT_PASSWORD} -v -e "USE ${WP_DB};";
	mysql -u root -p${MYSQL_ROOT_PASSWORD} -v -e "CREATE USER IF NOT EXISTS '${WP_USR_NAME}'@'localhost' IDENTIFIED BY '${WP_USR_PASSWORD}';"
	mysql -u root -p${MYSQL_ROOT_PASSWORD} -v -e "GRANT ALL PRIVILEGES ON ${WP_DB}.* TO '${WP_USR_NAME}'@'%' IDENTIFIED BY '${WP_USR_PASSWORD}' WITH GRANT OPTION;";
#	mysql -u root -p${MYSQL_ROOT_PASSWORD} -v -e "GRANT ALL PRIVILEGES ON ${WP_DB}.* TO '${WP_USR_NAME}'@'locahost' IDENTIFIED BY '${WP_USR_PASSWORD}' WITH GRANT OPTION;";
	mysql -u root -p${MYSQL_ROOT_PASSWORD} -v -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';";
	mysql -u root -p${MYSQL_ROOT_PASSWORD} -v -e "FLUSH PRIVILEGES;";
	if [ "$?" != 0 ];
	then
		echo -e "${RD}Error: mysql create database${NC}";
		echo -e "${YE}${SEP_SP}${NC}";
		return 1;
	fi;
	return 0;
}

function	main()
{
	echo -e "${YE}${SEP_SP}${NC}";
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	# START MYSQL SERVICE
	start_mysql;
	if [ "$?" != 0 ]; then return 1; fi;
	# CHECK MYSQL AND WORDPRESS SETUP
	check_mysql_wp_setup;
	if [ "$?" != 0 ]
	then
		# EXECUTE MYSQL SECURE INSTALLATION
		exec_mysql_secure_install;
		if [ "$?" != 0 ]; then return 1; fi;
		# WORDPRESS DATABASE AND USER SETUP
		create_wp_db;
		if [ "$?" != 0 ]; then return 1; fi;
	else
		echo -e "${GN}MYSQL and Wordpress database setup are already configured${NC}";
	fi;
	# STOP MYSQL SERVICE
	stop_mysql;
	if [ "$?" != 0 ]; then return 1; fi;
	# EXECUTE mysqld_safe TO GET PID 1 ON MARIADB CONTAINER
	exec mysqld_safe;
	if [ "$?" != 0 ];
	then
		echo -e "${RD}Error: start mysqld_safe${NC}";
		echo -e "${YE}${SEP_SP}${NC}";
		return 1;
	fi;
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