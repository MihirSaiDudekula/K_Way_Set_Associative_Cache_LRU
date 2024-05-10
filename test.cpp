#include "cache.h"

int main(){
	Kway<int, int> kway_cache(128, 4);

	cout<<"----PUTTING DATA----\n";
	for(int i=0; i<10; i++){
		kway_cache.PutData(i, i);
	}		
	cout<<"Current size of cache :"<<kway_cache.size()<<""<<endl;	
	cout<<"Number of lines in each Set :"<<kway_cache.num_lines()<<""<<endl;
	cout<<"Number of sets :"<<kway_cache.num_sets()<<""<<endl;
	cout<<"Cache Miss Count :"<<kway_cache.miss_count()<<""<<endl;
	cout<<"Cache Hit Count :"<<kway_cache.hit_count()<<""<<endl;

	cout<<"\n\n----GETTING DATA----\n";
	for(int i=0; i<10; i++){
		if(auto x = kway_cache.GetData(i)){
			cout<<*(int*)x<<endl;
		}
	}
	//cout<<kway_cache.GetData(1)<<endl;
	cout<<"Removing key 1 :"<<kway_cache.remove(1)<<endl;
	cout<<"Current Size  :"<<kway_cache.size()<<endl;	

	if(auto x = kway_cache.GetData(1)){
		cout<<*(int*)x<<endl;
	};
	kway_cache.remove(2);
	kway_cache.remove(3);
	cout<<"AVERAGE MEMORY ACCESS TIME: "<<kway_cache.AMAT()<<"seconds"<<endl;
	return 1;
}
