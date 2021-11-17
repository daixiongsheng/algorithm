/*
 * @lc app=leetcode.cn id=146 lang=golang
 *
 * [146] LRU 缓存机制
 */

// @lc code=start

type LRUCache struct {
	data map[int]interface{}
	lru []int
	size int
}


func Constructor(capacity int) LRUCache {
	this := LRUCache{}
	this.data = make(map[int]interface{}, capacity)
	this.size = capacity
	return this
}

func (this *LRUCache) Get(key int) int {
	if this.data[key] != nil {
		fmt.Println(this.data[key].(int))
		for i, v := range this.lru {
			if v == key {
				this.lru = append(this.lru[:i], this.lru[i+1:]...)
				this.lru = append(this.lru, key)
				return this.data[key].(int)
			}
		}
	}
	fmt.Println(-1)
	return -1
}

func (this *LRUCache) Put(key int, value int) {
	if this.data[key] != nil {
		this.data[key] = value
		for i, v := range this.lru {
			if v == key {
				this.lru = append(this.lru[:i], this.lru[i+1:]...)
				this.lru = append(this.lru, key)
				return
			}
		}
	}
	if len(this.lru) == this.size && this.size > 0 {
		first := this.lru[0]
		this.lru = this.lru[1:]
		delete(this.data, first)
	}
	this.data[key] = value
	this.lru = append(this.lru, key)
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
// @lc code=end

