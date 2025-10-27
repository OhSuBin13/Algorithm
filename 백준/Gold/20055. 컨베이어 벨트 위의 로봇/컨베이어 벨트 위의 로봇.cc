#include <iostream>
#include <vector>
#include <deque>
#include <numeric>

int main() {
    // C++ 표준 입출력 속도 향상
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, K;
    std::cin >> N >> K;

    // 벨트의 내구도를 저장할 deque (회전이 용이함)
    std::deque<int> durability(2 * N);
    int zero_durability_count = 0;
    for (int i = 0; i < 2 * N; ++i) {
        std::cin >> durability[i];
    }

    // 컨베이어 벨트의 윗부분(0 to N-1)에 있는 로봇의 위치를 저장
    std::deque<bool> robots(N, false);

    int stage = 0; // 진행 중인 단계

    while (true) {
        stage++;

        // 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
        durability.push_front(durability.back());
        durability.pop_back();
        
        robots.push_front(robots.back());
        robots.pop_back();

        // 회전 후 로봇이 내리는 위치에 도달하면 즉시 내린다.
        robots[N - 1] = false;

        // 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다.
        // (내리는 위치에 가까운 로봇부터 처리)
        for (int i = N - 2; i >= 0; --i) {
            // 현재 위치에 로봇이 있고, 다음 칸이 비어 있으며, 다음 칸의 내구도가 1 이상일 때
            if (robots[i] && !robots[i + 1] && durability[i + 1] >= 1) {
                // 로봇 이동
                robots[i + 1] = true;
                robots[i] = false;
                
                // 이동한 칸의 내구도 1 감소
                durability[i + 1]--;
            }
        }
        
        // 이동 후 로봇이 내리는 위치에 도달하면 즉시 내린다.
        robots[N - 1] = false;

        // 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
        if (durability[0] > 0) {
            robots[0] = true;
            durability[0]--;
        }

        // 4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다.
        zero_durability_count = 0;
        for(int d : durability) {
            if (d == 0) {
                zero_durability_count++;
            }
        }

        if (zero_durability_count >= K) {
            break;
        }
    }

    std::cout << stage << std::endl;

    return 0;
}