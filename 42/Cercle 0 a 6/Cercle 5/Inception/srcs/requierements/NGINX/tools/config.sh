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
function	check_file()
{
	echo -e "${YE}${SEP_SP}${NC}";
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	# CHECK IF INPUT FILE ALREADY EXISTS
	if ! [[ -e "${1}" ]];
	then
		echo -e "${RD}Warning: ${1} does not exist${NC}";
		return 1;
	else
		echo -e "${GN}Info: ${1} does exist${NC}";
	fi;
	return 0;
}

function	ssl_check_certificate()
{
	echo -e "${YE}${SEP_SP}${NC}";
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	# CHECK IF SSL SELFSIGNED CERTIFICATE ARE ALREADY PRESENT
	#check_file ${SSL_KEYOUT_PATH}/${SSL_KEYOUT_NAME};
	check_file ${1};
	if [ "$?" != 0 ]; then return 1; fi;
	#check_file ${SSL_OUT_PATH}/${SSL_OUT_NAME};
	check_file ${2};
	if [ "$?" != 0 ]; then return 1; fi;
	return 0;
}
function	ssl_create_certificate()
{
	echo -e "${YE}${SEP_SP}${NC}";
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	# CREATE SSL SELFSIGNED CERTIFICATE
	#openssl req -x509 -nodes -days ${SSL_DAYS} -newkey rsa:${SSL_RSA} -keyout ${SSL_KEYOUT_PATH}/${SSL_KEYOUT_NAME} -out ${SSL_OUT_PATH}/${SSL_OUT_NAME} -subj "/C=${SSL_COUNTRY}/ST=${SSL_STATE}/L=${SSL_LOCALITY}/O=${SSL_ORG_NAME}/OU=${SSL_ORGA_UNIT}/CN=${SSL_COMPANY}/emailAddress=${SSL_EMAIL}";
	openssl req -x509 -nodes -days ${1} -newkey rsa:${2} -keyout ${3} -out ${4} -subj "/C=${5}/ST=${6}/L=${7}/O=${8}/OU=${9}/CN=${10}/emailAddress=${11}";
	if [ "$?" != 0 ];
	then
		echo -e "${RD}Error: ssl create certificate${NC}";
		echo -e "${YE}${SEP_SP}${NC}";
		return 1;
	fi;
	return 0;
}

function	ssl_certificate()
{
	echo -e "${YE}${SEP_SP}${NC}";
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	ssl_check_certificate ${3} ${4};
	if [ "$?" != 0 ]
	then
		ssl_create_certificate ${1} ${2} ${3} ${4} ${5} ${6} ${7} ${8} ${9} ${10} ${11};
		if [ "$?" != 0 ]; then return 1; fi;
	fi;
	return 0;
}

function	nginx_create_vhost()
{
	echo -e "${YE}${SEP_SP}${NC}";
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	# CREATE VIRTUAL HOST sdestann.42.fr SYMBOLIC LINK
	#cd ${NG_SITE_ENABLED};
	cd ${3};
	#ln -s "${NG_SITE_AVAILABLE}/${DOMAIN_NAME}.conf";
	ln -s ${2}/${1}.conf;
	if [ "$?" != 0 ];
	then
		echo -e "${RD}Error: symbolic link creation${NC}";
		echo -e "${YE}${SEP_SP}${NC}";
		return 1;
	fi;
	return 0;
}

function	nginx_vhost()
{
	echo -e "${YE}${SEP_SP}${NC}";
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	# CHECK IF VIRTUAL HOST sdestann.42.fr ALREADY EXISTS
	#check_file ${NG_SITE_AVAILABLE}/${DOMAIN_NAME}.conf;
	check_file ${2}/${1}.conf;
	if [ "$?" != 0 ]; then return 1; fi;
	# CHECK IF VIRTUAL HOST sdestann.42.fr SYMBOLIC LINK ALREADY EXISTS
	#check_file ${NG_SITE_ENABLED}/${DOMAIN_NAME}.conf;
	check_file ${3}/${1}.conf;
	if [ "$?" != 0 ];
	then
		nginx_create_vhost ${1} ${2} ${3};
	fi;
	return 0;
}

function	nginx_rm_default_vhost()
{
	echo -e "${YE}${SEP_SP}${NC}";
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	rm -rf ${1};
	return 0;
}

function	nginx_start()
{
	echo -e "${YE}${SEP_SP}${NC}";
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	nginx -g "daemon off;";
	return 1;
#	if [ "$?" != 0 ]; then return 1; fi;
	return 0;
}

function	main()
{
	echo -e "${YE}${SEP_SP}${NC}";
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
#	ssl_certificate ${SSL_DAYS} ${SSL_RSA} ${SSL_KEYOUT_PATH}/${SSL_KEYOUT_NAME} ${SSL_OUT_PATH}/${SSL_OUT_NAME} ${SSL_COUNTRY} ${SSL_STATE} ${SSL_LOCALITY} ${SSL_ORG_NAME} ${SSL_ORG_UNIT} ${SSL_COMPANY} ${SSL_EMAIL};
#	if [ "$?" != 0 ]; then return 1; fi;
	nginx_vhost ${DOMAIN_NAME} ${NG_SITE_AVAILABLE} ${NG_SITE_ENABLED};
	if [ "$?" != 0 ]; then return 1; fi;
	nginx_rm_default_vhost ${NG_SITE_ENABLED}/default;
	nginx_start;
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