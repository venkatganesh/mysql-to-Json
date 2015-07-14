/*
 * mysqlJson.h
 *
 *  Created on: 13-Jul-2015
 *      Author: Venkatganesh
 */

#ifndef MYSQLJSON_H_
#define MYSQLJSON_H_
#include<mysql/mysql.h>

struct connection_details
{
    char *server;
    char *user;
    char *password;
    char *database;

};

MYSQL* mysql_connection_setup(struct connection_details mysql_details);

MYSQL_RES* mysql_perform_query(MYSQL *connection, char *sql_query);



#endif /* MYSQLJSON_H_ */
