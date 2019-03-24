# 将二进制的补码转化为10进制
### 知识补充：
* 正数的补码等于反码，原码
* 负数的原码到补码的转化方法为除了第一位不动，其他位取反再加1
    * 所以负数的补码到原码是减一再取反
```python
# python3把reduce移到了functools里
from functools import reduce
if __name__ == "__main__":
    num = list(map(int,input()))
    # print(num)
    if(num[0]==0):
        # 是正数的时候
        sum = reduce(lambda x,y:x*2+y,num)
        print(sum)
    elif num[0]==1:
        # 是负数的时候
        cnt = 0
        # 先颠倒 方便做减法
        # reversed后是generator，因此要用list
        num = list(reversed(num))
        # 0变为1，直到遇到1不用借位
        for i in num:
            # print(num)
            if i == 1:
                num[cnt] = 0
                break
            else:
                num[cnt] = 1
            cnt += 1
        # 颠倒回来
        num = list(reversed(num))
        # 取反
        num = list(map(lambda x:x^1,num))
        # 最高位变为0 1只是代表负数，其实这步应该不需要，如果补码不是10000000取反后最高位反码一定会是0
        num[0] = 0
        sum = reduce(lambda x, y: x * 2 + y, num)
        print(-1*sum )
```
