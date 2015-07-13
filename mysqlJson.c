/*
 * mysql.c
 *
 *  Created on: 13-Jul-2015
 *      Author: Venkatganesh
 */
#include<mysql/mysql.h>
#include"mysqlJson.h"
#include<stdio.h>
#include <stdlib.h>

/**** Connection Parameter *****/
#define SERVER "127.0.0.1"
#define USERNAME "Test"
#define PASSWORD "password"
#define DATABASES ""

MYSQL* mysql_connection_setup(struct connection_details mysql_details)
{
     // first of all create a mysql instance and initialize the variables within
    MYSQL *connection = mysql_init(NULL);

    // connect to the database with the details attached.
    if (!mysql_real_connect(connection,mysql_details.server, mysql_details.user, mysql_details.password, mysql_details.database, 0, NULL, 0)) {
      printf("Conection error : %s\n", mysql_error(connection));
      exit(1);
    }
    return connection;
}

MYSQL_RES* mysql_perform_query(MYSQL *connection, char *sql_query)
{
   // send the query to the database
   if (mysql_query(connection, sql_query))
   {
      printf("MySQL query error : %s\n", mysql_error(connection));
      exit(1);
   }

   return mysql_use_result(connection);
}

int main(){

	  MYSQL *conn;		// the connection
	  MYSQL_RES *res;	// the results
	  MYSQL_ROW row;	// the results row (line by line)

	  struct connection_details mysqlD;
	  mysqlD.server = SERVER;  // where the mysql database is
	  mysqlD.user = USERNAME;		// the root user of mysql
	  mysqlD.password = PASSWORD; // the password of the root user in mysql
	  mysqlD.database = DATABASES;	// the databse to pick

	  // connect to the mysql database
	  conn = mysql_connection_setup(mysqlD);

	  // assign the results return to the MYSQL_RES pointer
	  res = mysql_perform_query(conn, "select * from Scene1");
	  MYSQL_FIELD *field;
	  int num_fields = mysql_num_fields(res);
	  int i;
	  while ((row = mysql_fetch_row(res)))
	  {
	      for(i = 0; i < num_fields; i++)
	      {
	          if (i == 0)
	          {
	             while((field = mysql_fetch_field(res))){

	                printf("%s ", field->name);
	             }

	             printf("\n");
	          }

	          printf("%s  ", row[i] ? row[i] : "NULL");
	      }
	  }
	  /* clean up the database result set */
	  mysql_free_result(res);
	  /* clean up the database link */
	  mysql_close(conn);

	  return 0;
}

