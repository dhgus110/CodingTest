    /*
    1. 초마다 로봇이 지나간 경로를 저장하는 변수 만들기   vertor<pair<int,int> paths[]
    1-1. 모든 로봇이 도착했는지에 대한 변수 만들기   bool[] visited
    1-2. 현재 로봇 위치 체크하는 변수 vector<pair<int,int>> []
    1-3. 로봇이 도착해야하는 위치를 저장한 변수 vector<pair<int,int>> []
    2. 최단경로 찾기 알고리즘 이용 x
    3. (r,c) 좌표에서 r이 우선 순위가 높으니 r먼저 이동한 다음 c 이동
    */
    #include <string>
    #include <vector>
    #include <map>
    #include <iostream>

    using namespace std;

    map<pair<int, int>, int> paths[10001]; // 초마다 로봇이 지나간 경로 저장 <경로, 그 경로에 있는 로봇 수>
    vector<pair<int, int>> robotPos[100]; // 현재 로봇 위치
    vector<pair<int, int>> goalPos[100]; // 로봇이 들려야하는 위치들 (들려야하는 곳이 여러 곳 있을 수 있다)
    // vector<vector<bool>> passCheck;  // 로봇이 들렸던 곳 체크
    bool **visit; // [i번째 로봇][들려야하는 지점들]
    int robotSize, routesSize;

    void init(vector<vector<int>> const& points,vector<vector<int>> const& routes){
        robotSize= routes.size();
        routesSize= routes[0].size();

        for (int i = 0; i < robotSize; i++){
            robotPos[i].push_back(make_pair(points[routes[i][0] - 1][0], points[routes[i][0] - 1][1]));
            for(int j = 1 ; j < routesSize ; j++)
                goalPos[i].push_back(make_pair(points[routes[i][j] - 1][0], points[routes[i][j] - 1][1]));
        }

        visit = new bool *[robotSize];
        for (int i = 0; i < routes.size(); i++)
            visit[i] = new bool[routesSize];
        fill_n(&visit[0][0], robotSize * routesSize, false);

    }

    bool isAllArrived(){
        for (int i = 0; i < robotSize; i++){
            for (int j = 0; j < routesSize; j++)
                if (!visit[i][j])
                    return false;   
        }
        return true;
    }

    //todo 여기 구간 잘 못됨 ; 하나씩 전부 뒤집어 보자
    void pathStore(vector<vector<int>> const& points){
        int curTime = 0;
        for (int i = 0; i < robotSize; i++){
            paths[curTime][robotPos[i][0]]++;
        }

        while(!isAllArrived()){
            curTime++;

            for (int i = 0; i < robotSize; i++){

                //현재 로봇이 가야하는 지점
                int nextGoalPoint = routesSize - 1;
                for (int x = 0; x < routesSize; x++){
                    if(!visit[i][x]) {
                        nextGoalPoint = x;
                        break;
                        }
                }

                //현재 로봇 모든 지점을 들렸다면 continue
                if (visit[i][nextGoalPoint])
                    continue;

                auto cur = robotPos[i][0];
                auto next = goalPos[i][nextGoalPoint];

                //이동
                if (cur.first > next.first)
                    robotPos[i][0] = make_pair(cur.first - 1, cur.second);
                else if (cur.first < next.first)
                    robotPos[i][0] = make_pair(cur.first + 1, cur.second);
                else if (cur.first == next.first)
                {
                    if (cur.second > next.second)
                        robotPos[i][0] = make_pair(cur.first, cur.second - 1);
                    else if (cur.second < next.second)
                        robotPos[i][0] = make_pair(cur.first, cur.second + 1);
                }

                //도달했는지 체크 
                if (!visit[i][nextGoalPoint]){
                    paths[curTime][robotPos[i][0]]++;

                    if (robotPos[i][0] == next)
                        visit[i][nextGoalPoint] = true;
                }
            }
        }
    }

    int calculate(){
        int crashCnt = 0;
        for(int i = 0 ; i < 10001 ; i++){
            cout<<i<<"초"<<'\n';
            for(auto iter : paths[i]){
                cout<<"("<<iter.first.first<<","<<iter.first.second<<"), ";
                if(iter.second >1) crashCnt++;
            }
            cout<<endl;
        }

        return crashCnt;
    }

    int solution(vector<vector<int>> points, vector<vector<int>> routes) {
        init(points, routes);
        pathStore(points);
        return calculate();
    }