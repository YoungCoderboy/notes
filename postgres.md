# Introduction

- Postgres uses SQL
- Database is place where you can store, Manipulate, and retrieve data
- postgres is actual database engine and SQL is language
- SQL is programming language help to interact with database
- SQL help to manage data held in relational database

example :

```sql
SELECT * FROM TABLE_NAME
```

- Data is stored in tables
- It is called as relational database because it can have relation between multiple tables
- PostGres is Object-Relational Database management system which allows us manage database
- There are multiple way to connect to pg
  1. Client
  2. GUI
  3. Terminal
  4. Application

# Commands

- `CREATE DATABASE <NAME>` : Use create database
- `\l` to list all the database
- `psql -h localhost -U username -p 5432 <db_name>` use this command to connect ot database
- `\c <db_name>` from inside psql : to change the db
- `DROP DATABASE <db_name>` : Delete the database

## Create table

```sql
CREATE TABLE <table_name> (
 Column Name + data type + constrain
)
```

example:

```sql
CREATE TABLE person (
  id int,
  first_name VARCHAR(50),
  last_name VARCHAR(50),
)

```

- There is vast list of supported datatype

- `\d` to list all the tables
- `\d <table_name>` describe the table

## Constrain

```sql
CREATE TABLE person (
  id BIGSERIAL NOT NULL PRIMARY KEY,
  first_name VARCHAR(50) NOT NULL,
  last_name VARCHAR(50) NOT NULL,
)
```

- `DROP TABLE <table_name>` Delete the table

TODO: ADD Constrain without deleting the table

## Insert Record into Tables

```sql
INSERT INTO <table_name>(
  first_name,
  last_name
) VALUES ('Deep' , 'Onkar');
```

- each database can have multiple tables
- multiple constrain is added in serial ways

```sql
INSERT INTO <table_name> (
    first_name,
    last_name,
    date_of_birth
) VALUES ('Deep', 'Onkar' , DATE '2000-02-20');

```

- use `mockaroo.com` to generate the realistic data
- `\i <file_name>` to execute command from file

## Read From data

```sql

SELECT * FROM <table_name>

```

- here `*` is to select rows

## Sort Data

- `order by` by default sort by asc order
- use `DESC` to sort in descending order

```sql
SELECT * FROM <table_name> ORDER BY <row_name> ASC
```

## Distinct

```sql
SELECT DISTINCT <row_name> FROM <table_name>;
```

## WHERE clause

- allows use to filter data using some condition

```sql
SELECT * FROM <table_name> WHERE <condition>
```

## Operator

- `=` comparator in case of where clause
- `>` or `<` or `<=` or `>=` are other comparator operators
- `<>` not equal operator

## Limit, OFFSET and FETCH

- if you want to limit number of records you get use `LIMIT` keyword

```sql

SELECT * FROM <table_name> LIMIT 10;
```

- if you want to ignore certain number use `OFFSET` keyword
- `FETCH` is same as `LIMIT` only difference is that `FETCH` is official term to get certain rows in sql

## IN

```sql

SELECT * FROM <table_name> WHERE <column> IN ('' , '' , ...);
```

## BETWEEN

- use to find data in range

```sql
SELECT * FROM <table_name> WHERE <column> BETWEEN DATE '2020-01-01' AND `2021-01-01`
```

## LIKE and ILIKE

- use to filter data based on pattern
- ILIKE ignore the casing issue

```sql
SELECT * FROM <table_name> WHERE <column> LIKE <pattern>
```

## GROUP BY

- allow us to group data based on column

```sql
SELECT <column>, COUNT(*) FROM <table_name> GROUP BY <column>
```

## GROUP BY HAVING

```sql
SELECT <column>, COUNT(*) FROM <table_name> GROUP BY <column> HAVING COUNT(*) > 10;
```

- function we have seen are the aggregation functions

## MAX, MIN, SUM , AVG , ROUND

```sql
SELECT MAX(<column> or <expression>) FROM <table_name>
```

```sql
SELECT SUM(<column> or <expression>) FROM <table_name>
```

## Arithmetic operators

- `-` , `+` , `%` , `^`
- `!` factorial

## Alise

- use to override or name any column

```sql

SELECT <column_name>, (price * 0.5) AS discount FROM <table_name>;

```

## COALESCE

- allow you to have default value if something is going to be null

```sql
-- Example

SELECT COALESCE(alternative_email , email , "NO EMAIL PROVIDED") AS Email from person;
```

## Timestamp

- `SELECT NOW()` will give the current timestamp
- `INTERVAL` can use to add or sub date

2:26
