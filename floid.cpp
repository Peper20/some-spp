#include <iostream>

int main(){
	long long n;
	
	std::cin>>n;

	long long m[n][n];
	long long inf = 1000000000;
	
	for (long long i = 0; i < n; i++){
		for (long long j = 0; j < n; j++){
			long long a;
			std::cin>>a;
			if (a != -1){
				m[i][j] = a;
			} else{
				m[i][j] = inf;
			}
		}
	}

	for (long long k = 0; k < n; k++){
		for (long long i = 0; i < n; i++){
			for (long long j = 0; j < n; j++){
				long long d = m[i][k] + m[k][j];
				if (m[i][j] > d){
					m[i][j] = d;
				}
			}
		}
	}

	long long answer = -1;
	for (long long i = 0; i < n; i++){
		for (long long j = 0; j < n; j++){
			if(m[i][j] > answer && m[i][j] < inf){
				answer = m[i][j];
			}
		}
	}

	std::cout<<answer;
	
	return 0;
}
