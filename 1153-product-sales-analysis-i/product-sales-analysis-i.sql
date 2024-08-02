# Write your MySQL query statement below
SELECT 
    P.product_name, S.year, S.price 
FROM 
    (SELECT product_id, year, price FROM Sales) S
INNER JOIN Product AS P
USING (product_id);