#include<iostream>
using namespace std;

typedef struct _Point {
	int y, x;
}Point;

int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
char command[501];

void read() {
	scanf("%s",command);
}

int solve() {
	Point c = {0,0};
	int min_x = 0, max_x = 0, min_y = 0, max_y = 0;
	int d = 0;

	for (int i = 0; command[i] != NULL; i++) {
		switch (command[i]){
		case 'L':
			d = (d + 3) % 4;
			break;
		case 'R':
			d = (d + 1) % 4;
			break;
		case 'F':
			c.y += dy[d], c.x += dx[d];
			break;
		case 'B':
			c.y += dy[(d+2)%4], c.x += dx[(d+2)%4];
			break;
		}

		if (c.x > max_x) max_x = c.x;
		if (c.x < min_x) min_x = c.x;
		if (c.y > max_y) max_y = c.y;
		if (c.y < min_y) min_y = c.y;
	}
	
	return (max_x - min_x)*(max_y - min_y);
}

int main() {
	int T;
	scanf("%d",&T);

	for (int t_case = 1; t_case <= T; t_case++) {
		read();
		int answer = solve();
		printf("%d\n",answer);
	}
	return 0;
}
