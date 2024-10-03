# Introduction

- Elastic Stack: Is a group of open source products build by elastic

1. Elastic Search

- open source analytics and full text search engine
- Build in java
- easy to use and highly scalable
- often use to provide search functionality to an application with feature like auto completion, correcting typos , handling synonyms

2. Kibana

- dashboard for analyzing and data visualize

3. LogStash

- Process logs from application and send them to elastic search. But over the time it has evolved
- logstash is a free and open server-side data processing pipeline that ingest data from the multitude of source, transform it and sends it to your favorite stash (kafka/elasticSearch)

4. Beats

- Beats is collection of data shippers. They are light weight agents which send data from hundred and thousands of machine and systems to logstash or elastic search
- Different kind of beats do different kind of tasks

5. X-Pack

- Adds additional feature to elasticsearch and kibana

  - security
  - monitor the performance of elastic stack
  - enable machine learning on kibana and elastic search
  - graph
  - Elastic SQL
    - SQL API: SQL query -> Results
    - Translate API: SQL query -> Query DSL (Domain Specific Language)

- We can put data in elastic search via beats , logstash or even directly through elastic search apis
- Kibana is UI that site on elastic search and visualize elastic search data

# Terms

- Node is one instance of elastic search
- Group of nodes is called cluster specific cluster do specific task 
- Data is store in JSON format in Elastic Search, Store format not only contain data but also contain meta data like index, type, id
- MetaData + JSON = Document 
- Key starts with underscore 
- Data is store in "_source"
- `_index` is table name in SQL (identifier)
- `fields` is column in SQL 
- `document` is row in SQL
- documents are group together by indices 



 