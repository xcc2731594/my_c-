#include <iostream>
#include <mysql/mysql.h>
#include <string.h>
using namespace std;
int main()
{
    MYSQL *mysql = mysql_init(NULL);
    mysql = mysql_real_connect(mysql,"localhost","root","root","user",0,NULL,0);
    cout<<mysql<<endl;
    mysql_query(mysql,"set names utf8;");
    mysql_query(mysql,"use user;");
    mysql_query(mysql,"select * from xiaoming");
    MYSQL_RES *res = mysql_store_result(mysql);
    MYSQL_ROW row;
    row = mysql_fetch_row(res);
    cout<<row[0]<<endl;
    cout<<row[1]<<endl;
    string a = mysql_fetch_field(res)->name;
    cout<<a<<endl;
    a = mysql_fetch_field(res)->name;
    cout<<a<<endl;
    cout<<mysql_num_rows(res)<<endl;
   
 
  
 
}