#include <iostream>
#include <set>

int max(int t[], int n){
	int max = -1;
	for(int i = 0; i < n; i++){
		if(max<t[i]){
			max = t[i];
		}
	}

	return max;
}

int main() {
	int n, s, f;
	std::cin>>n>>s;
	s -= 1;
	f -= 1;
	int matrix[n][n];

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			std::cin>>matrix[i][j];
		}
	}

	int inf = 1000000000;
	int t[n];
	for(int i = 0; i < n; i ++){
		t[i] = inf;
	}	
	t[s] = 0;
	std::set <int> p;
	p.insert(s);

	while (s != -1){
		for (int j = 0; j < n; j++){
			if (matrix[s][j] != -1){
				int w = t[s] + matrix[s][j];

				if (w < t[j]){
					t[j] = w;
				}
			}
		}

		s = -1;
		int m = max(t, n);

		for(int i = 0; i < n; i++){
			if(t[i] < m && not p.count(i)){
				m = t[i];
				s = i;
			}
		}

		if(s != -1){
			p.insert(s);
		}
	}

	// if(t[f] != inf){
		// std::cout<<t[f];
	// } else{
		// std::cout<<-1;
	// }

	for (int i = 0; i < n; i ++){
		std::cout<<t[i]<<' ';
	}

	return 0;
}
