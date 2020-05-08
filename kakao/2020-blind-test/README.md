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
* 얼마나 잘 구현해내는가의 문제
* 괄호 set의 범위가 주어지면 거기서 u와 v의 경계 지점(i)를 구해준다. u의 맞고 안맞고를 확인해주기(result) 위해 correct 함수를 만든다. 
* 만약 correct 함수에서 begin과 end 가 같을 때는 그냥 begin과 1을 반환해주었다. 
* v의 범위가 s범위 밖으로 벗어나는 것을 방지한다. 
```c++
if (x2 >= n || y2 >= n) s2 = "";
```

### 코드 (C++) 
``` C++
#include <string>
#include <vector>
#include <stack>
#define pill pair <int, int>
using namespace std;

string p;
int n; 
pii correct (int begin, int end) {
     stack<int> s; 
     int result = 1;
     int o = 0, x = 0;
     for (int i = begin; i <= end; i++){
         if (p[i] ==')') {
               o++; 
               if (s.empty()) result = 0;
               else s.pop();
         }
         else {
               s.push(1); x++;
         }
         if (0 ==x) return pii(i, result);
     }
     return pii(begin,1);
}

string _solution(int begin, int end){
      string result = "";
      if(begin == end) return "";
      pii r = correct(begin, end);
      int x1 = begin, y1 = r.first, x2 = r.first+1, y2 = end;
      string s2 = "";
      if (x2 >= n || y2 >= n) s2) = "";
      else s2 = _solution(x2, y2);
      if (r.second) return p.substr(x1, y1-x1+1) +s2;
      result = "(" + s2 + ")";
      for (int i = x1 + 1; i <= y1-1; i++){
         if (p[i] == '(') result += ")";
         else result += "(";
      }
      return result;      
}

string solution (string _p){
      p = _p, n = p.length();
      return _solution(0,n-1);
}


```

