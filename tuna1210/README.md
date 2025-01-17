<p align="center">
<a href=https://solved.ac/tuna1210>
<img src="http://mazassumnida.wtf/api/v2/generate_badge?boj=tuna1210" alt="text" width="70%"/>
</a>
</p>

***  

# 알고리즘 정리

## CCW
Counter Clock Wise, 세 점이 순서대로 시계방향인지 아닌지 검사하는 방법.  
아래 신발끈공식(외적)을 이용. S가 ``음수라면 시계, 0이면 직선, 양수면 반시계방향``이다.  
* 신발끈 공식   
![신발끈](https://mblogthumb-phinf.pstatic.net/20160530_226/10baba_14645967148306TPeY_PNG/%BB%E7%BC%B1%BD%C4.png?type=w2)


* 예제 : **중간에 더해가는 과정에서 OVFL가 일어날 수 있음을 주의**
```
int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    long long temp = 1l * a.first * b.second + 1l * b.first * c.second + 1l * c.first * a.second;
    temp -= 1l * b.first * a.second + 1l * c.first * b.second + 1l * a.first * c.second;
    if(temp > 0) return 1;
    else if(temp < 0) return -1;
    return 0;
}
```
***
## Bellman Ford
시간복잡도는 $O(VE)$이다. 최단 경로를 찾아내는 알고리즘으로, 다익스트라와는 달리 음의 가중치를 지닌 간선을 가질 수 있지만 ``음의 사이클(사이클 가중치의 합이 음수)은 가질 수 없다``. 만약 음의 사이클이 존재하지 않는다면 노드의 개수를 $N$이라 하였을 때 $N-1$번 모든 간선에 대해 Relaxation을 수행하여 정해를 구할 수 있다. 이떄 만약 음의 사이클이 존재한다면 $N$번째 수행 시 Relaxation이 발생한다. 이를 이용하여 음의 사이클의 존재여부를 판단할 수 있다.  


* 유의할 점 ([할로윈 묘지](https://www.acmicpc.net/problem/3860))  
<img src = "https://i.ibb.co/s3GzWWk/IMG-50-EE9614-E6-F9-1.jpg" width="60%">  
이와같은 상황일때 노드를 순회하면서 $dist[n] ≠ \infty$ 을 검사하지 않는다면 파란색 웜홀에 도달할 수 있는 방법이 존재하지 않음에도 불구하고 웜홀 스스로 relaxation이 발생하여 경로 상에 음의 사이클이 있다고 판단함. 따라서 dist가 INF가 아닌 노드에 대해서는 relaxation이 가능하더라도 그것을 수행해서는 안된다.

***
## Dijkstra
**[13907 세금](https://www.acmicpc.net/problem/13907)**   
$dist$ 배열을 \[노드]\[거쳐온 노드 수]로 2차원으로 선언, 문제의 input이 $N ≤ 1000$ 이므로 거친 노드의 최대값은 1000이다. 따라서 다익스트라를 실행할때 거친노드가 1000을 넘어간다면 무시하도록 예외 처리를 해주어야 한다. 
```
if(nextMove == 1000) continue;
```
또 다른 풀이 : 더 높은 비용을 가지고 더 많은 노드를 거쳐온 경로는 최적해가 되지 않음이 보장되므로 큐에 집어 넣지 않아도 된다. 1 - 2 - 1 - 2 - 1 - ... 같은 경우. (최소비용을 저장하는 minDist 배열과 그 최소비용의 경로 길이를 저장하는 path 배열을 추가로 만듬)
```
if(minDist[nextInd] > curCost + nextCost)
{
    minDist[nextInd] = curCost + nextCost;
    path[nextInd] = nextMove;
    dist[nextInd][nextMove] = curCost + nextCost;
    pq.push({dist[nextInd][nextMove], {nextInd, nextMove}});
}
else if(dist[nextInd][nextMove] > curCost + nextCost && path[nextInd] > nextMove)
{
    dist[nextInd][nextMove] = curCost + nextCost;
    pq.push({dist[nextInd][nextMove], {nextInd, nextMove}});
}
```
세금 인상 계산 부분은 minDist와 path 배열을 이용하여 최적화가 가능해진다.
```
for (const auto& curTax : tax)
{
    min = INF;
    for (int i = 0; i <= minMove; i++)
    {
        if(dist[d][i] == INF) continue;
        tmp = curTax * i;
        if(min > dist[d][i] + tmp)
        {
            min = dist[d][i] + tmp;
            maxCnt = i;
        }
        dist[d][i] += tmp;
    }
    minMove = maxCnt;
    cout << min << "\n";
}
```


***
## 소수판정

에라토스테네스의 체를 이용하여 $n$까지의 소수를 구해야 할 때 $\sqrt{n}$까지의 배수만 제거해도 정답이 보장된다.

***
## Set / Map 에 배열 사용
[1525 퍼즐](https://www.acmicpc.net/problem/1525)  
구조체나 클래스를 `set` 이나 `map` 에 사용하고자 할때, `set` 과 `map` 은 정렬이 필요하므로 연산자 오버로딩을 통해 구조체가 비교가 가능하게 하는 작업을 필요로 한다. 만약 변수가 1~3개 정도라면 가능하지만 이 문제에서는 구조체 멤버인 **2차원 배열을 문자열로 바꿔서** `unordered_set<string> visited` 로 사용하였다.

***
## 분할정복을 이용한 최댓값 구하기
LIS 문제를 풀다가 최댓값을 $logn$안에 구할 수 있는 방법을 찾다가 생각나서 해봤는데 시간초과가 났다. 나는 당연히 선형 탐색보다 빠를 줄 알았는데 알고보니 당연히 아니었다.  
점화식을 구해보면 $T(n)=2 \times T({n \over 2}) + 2$가 나오는데 , 이를 마스터 정리를 이용해 시간복잡도를 계산해보면  
$ a = 2, b = 2, f(n) = 2$ 이므로 $h(n)=n^{log{_ba}}=n^{log{_22}}=n$이고,
$n\rightarrow\infty$일 때 $h(n) > f(n)$이므로  $\Theta(h(n)) = \Theta(n)$이다.  
이분탐색은 똑같이 반으로 쪼개지만 안봐도 되는 반절은 안보니까 $O(log{n})$이 가능한데, 여기서는 결국에는 모두 다 탐색하므로 똑같은 듯

***
## 비트마스킹
* [외판원 순회](https://www.acmicpc.net/problem/2098)
    * 현재 위치와 갈 곳이 같을 때를 안 걸러줘도 되는 이유 (`cur == i`) : 이미 현재 위치 `cur`은 `status`에 이미 비트마스킹이 되어있기 때문에 `status & (1 << i)) == (1 << i)`에서 걸러진다.
    * 함수 처음 시작할 때 0에서 시작했으니 0번 비트를 마스킹 해주고 시작해야 한다. (`solve(0, (1 << 0))`)
* [달이 차오른다, 가자](https://www.acmicpc.net/problem/1194)
    * `visited` 배열의 비트마스킹 부분에서 시작 좌표의 열쇠를 초기화 할 때 `visited[x][y][1 << 6] = true` 으로 초기화 하면 안된다. 왜냐하면 `visited` 배열을 `visited[n][m][1 << 6]` 으로 생성하였기 때문에 `visited` 배열의 크기는 $N\times M\times 2^6$ 인데, 여기서 열쇠가 하나도 없다는 것을 뜻하는것은 $2^6$가 아닌 $0$이므로 `visited[x][y][0] = true`으로 초기화 해야 한다.

***
## 세그먼트 트리
* 주의할 점: Update시 실제 배열 값도 바꿔줘야함