--
-- @lc app=leetcode.cn id=176 lang=mysql
--
-- [176] 第二高的薪水
--

-- @lc code=start
select IFNULL((select distinct Salary
from Employee
order by Salary desc
limit 1, 1), null) as SecondHighestSalary


-- @lc code=end

