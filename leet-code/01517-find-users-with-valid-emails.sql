SELECT *
FROM Users
WHERE mail RLIKE '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\\.com$';
