//#include "Mem.h"

template<typename T>
std::ostream & operator<<(std::ostream & o,const Mem<T> & mem)  {
	for (int i = 0; i < SIZE; i++)
		o << "loc " << i << " " <<  mem.mem_arr[i] << std::endl;
	return o;
}
template<typename T>Mem<T>::Mem(): mem_arr(new T [SIZE]()){}
template<typename T>Mem<T>::~Mem() {std::cout << "mem dest" << std::endl; delete [] mem_arr; }

template<typename T> T Mem<T>::read(int addr) {
	checkAddr(addr);
	return mem_arr[addr];
}
template<typename T> void Mem<T>::write(int addr, T data) {
	checkAddr(addr);
	mem_arr[addr] = data;
}
template<typename T> T & Mem<T>::operator[](int addr) {
	checkAddr(addr);
	return(mem_arr[addr]);
}