--
-- @lc app=leetcode.cn id=1965 lang=mysql
--
-- [1965] 丢失信息的雇员
--

-- @lc code=start
# Write your MySQL query statement below
with tmp as(
    select employee_id from employees
    union all
    select employee_id from salaries
)
select
employee_id
from tmp t group by 1 having count(1)=1 order by 1
-- @lc code=end

