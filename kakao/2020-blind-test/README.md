# 2020 블라인드 코딩 테스트 

## 문제1 
[기출문제](https://tech.kakao.com/2019/10/02/kakao-blind-recruitment-2020-round1/)

### 출제 의도 
* 문자열을 다룰 수 있고, 예시와 관련된 문자열 작업 가능한지 파악
    * 문자열 자르기 
    * 부분 문자열 얻기 
    * 문자열 비교하기 
    * 문자열 길이 얻기 
    

### 프로그래밍 
* 문자열 길이가 최대 1000으로 제한이 크지 않기 때문에, 가능한 모든 방법을 탐색하면 된다. 
문자열 길이가 N일 때, 길이가 N/2보다 크게 잘랐을 때 길이가 줄지 않는다.
따라서 1 ~ N/2 길이로 자르는 방법을 모두 탐색한 후 그중 가장 짧은 방법을 선택하면 된다. 

* 입력값 문자열 S를 쪼개는 단위인 K를 1개부터 n/2개까지 보면서 k일 때의 압축된 글자의 수 cnt를 확인한다. 
이를 위해 i번째(비교대상)와 j번째(그 뒤의 샘플)를 비교해 나간다. 
  * 두 개가 같다면 j를 i+K로 업데이트 해서 다시 비교해주고 same_n의 개수를 늘린다. 
  * 다르다면 그때는 same_n의 개수를 확인해서 이에 맞게 cnt를 업데이트 해준다. 
* 그리고 모든 k의 cnt 중에서 제일 작은 값을 ans로 반환한다. 

### 오류 
입력값 〉	"ababcdcdababcdcd"
기댓값 〉	9
아래 코드 > 12 
(오류)

### 코드 (C++)
```C++
# include <string>
# include <vector>
using namespace std;

int solution(string s) {
  int n = s.length(), ans = n;
  for (int k = 1; k < n/2; k++){
    int cnt = 0, i=0;
    // 비교대상 i 
    while (i < n) {
      int same_n = 0, next = 0; 
      if (i + k > n) {
          cnt += n-i; break;
       }
       // 샘플 j 
       for (int j = i +k; j < n; j+= k){
            //비교 시작 
            int t; 
            for (t = 0; t < k; t++) {
                // 다른 게 하나라도 있으면 0으로 
                if (s[i+t] != s[j+t]) break;
             }
             if (t == k) same_n++;
             else {
                 next = j; break;
             }
        }
        if (same_n) {
              if (same_n + 1 <= 9) cnt += k+1;
              else if (same_n + 1 <= 99) cnt += k+2;
              else if (same_n + 1 <= 999) cnt += k+3; 
              else cnt += k + 4; 
         }
         else cnt += k;
         if (next == 0) break;
         i = next;
       }
      if (cnt < ans) ans = cnt;
  }
return ans;
}
```


## 문제 2 
[기출문제](https://tech.kakao.com/2019/10/02/kakao-blind-recruitment-2020-round1/)
1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다.
2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다.
3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
  3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다.
4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다.
  4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다.
  4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다.
  4-3. ')'를 다시 붙입니다.
  4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
  4-5. 생성된 문자열을 반환합니다.
  
### 출제의도 
* 주어진 로직을 그대로 구현할 수 있는가
* 재귀함수를 이해하고 작성할 수 있는가 
### 프로그래밍 
* 재귀함수로 구현하면 복잡도가 O(n^2)인데 n=1000이라 문제 없다.
```c++
if (x2 >= n || y2 >= n) s2 = "";
```

### 코드 (C++) 
``` C++
#include <string>
#include <vector>
using namespace std;
 
string solution(string p) {
    if (p.size() == 0) return "";
    int a = 0, b = 0;
    for (int i = 0; i < p.size(); i += 2) {
        if (p[i] == '(') a++;
        else b++;
        if (p[i + 1] == '(') a++;
        else b++;
        if (a == b) {
            int cnt = 0;
            bool bal = 1;
            for (int j = 0; j < i + 2; ++j) {
                if (p[j] == '(') cnt++;
                else cnt--;
                if (cnt < 0) bal = 0;
            }
            if (bal) {
                return p.substr(0, i + 2) + solution(p.substr(i + 2, p.size() - i - 2));
            }
            else {
                string ret = "(";
                ret += solution(p.substr(i + 2, p.size() - i - 2));
                ret += ')';
                for (int j = 1; j < i + 1; ++j) {
                    if (p[j] == '(') ret += ')';
                    else ret += '(';
                }
                return ret;
            }
        }
    }
}

```

