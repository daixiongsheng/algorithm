/**
 * @Date         : 2020-06-29
 * @LastEditors  : daixiongsheng
 * @LastEditTime : 2020-07-12
 * @FilePath     : /js/100.js
 * @Description  :
 */


/**
 * http:

 完成将 toChineseNum，
 可以将数字转换成中文大写的表示，处理到万级别，
 例如 toChineseNum(12345)，返回 一万二千三百四十五。

 */


//只能处理亿以下
const toChineseNum = num => {
    const UNIT = ' 十百千万'
    const CN = '零一二三四五六七八九'
    let arrNum = num.toString().split('').reverse()
    let strArr = arrNum.map((v, i) => {
        if (i === 4 && parseInt(v) === 0) {
            return '万'
        }
        i = i > 4 ? i - 4 : i;
        return parseInt(v) === 0 ? CN[v] : CN[v] + UNIT[i - 0]
    })
    return strArr.reverse().join('').replace(/(零(?=零))|(零$)|(零(?=万))/g, '').replace(/\s+/g,'')
}
console.log(toChineseNum(98063001))