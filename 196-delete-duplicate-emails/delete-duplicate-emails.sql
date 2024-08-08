# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
DELETE FROM Person WHERE Id not IN 
(SELECT * FROM(
    SELECT min(Id) FROM Person GROUP BY Email) as p);