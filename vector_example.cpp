#include <iostream>
#include <set>
#include <vector>


int n;
std::set <int> f;

void poisk(std::vector<std::vector<int>>&m, int s){
	for (int i = 0; i < n; i++){
		if(not f.count(i) && m[s][i] == 1){
			f.insert(i);

			poisk(m, i);
		}
	}
}

int main(){
	int s;
	std::cin>>n>>s;
	std::vector <std::vector<int>> m (n, std::vector<int>(n, 0));
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			std::cin>>m[i][j];
		}
	}

	poisk(m, s);

	if(f.size() != 0){
		std::cout<<f.size() - 1;
	} else {
		std::cout<<0;
	}
}
