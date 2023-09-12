# Write your MySQL query statement below

# Method 1
# SELECT x, y, z,
# IF(x+y>z AND x+z>y AND y+z>x, 'Yes', 'No') as triangle
# FROM Triangle;


# Method 2
SELECT x, y, z,
CASE
WHEN x+y > z AND x+z > y AND y+z > x THEN 'Yes'
ELSE 'No'
END AS triangle
FROM Triangle; 