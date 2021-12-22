--
-- @lc app=leetcode.cn id=175 lang=mysql
--
-- [175] 组合两个表
--

-- @lc code=start

select FirstName, LastName, City, State
from Person left join Address using(PersonId);


-- @lc code=end

