#include <map>
#include <iostream>

class MetricRegister;

class SingletonDestroyer
{
private:
	static MetricRegister *p_instance;
public:
	~SingletonDestroyer() { delete p_instance; }
	void initialize(MetricRegister* p) { p_instance = p; }
};

class MetricRegister {
private:
	static MetricRegister* p_instance;
	static SingletonDestroyer destroyer;
protected:
	MetricRegister() {}
	MetricRegister(const MetricRegister&);
	MetricRegister& operator = (MetricRegister&);
	~MetricRegister() {}
	friend class SingletonDestroyer;
public:
	static MetricRegister* getInstance() {
		if (!p_instance)
		{
			p_instance = new MetricRegister();
			destroyer.initialize(p_instance);
		}
		return p_instance;
	}
private:
	std::map<int, std::pair<int, int>> associatedArray;
public:
	//добавление метрики
	bool add_metr(int key, int resp_t, int wait_t) {
		try {
			associatedArray.insert(std::pair<int, std::pair<int, int>>(key, std::pair<int, int>(resp_t, wait_t)));
			return true;
		}
		catch (...) {
			return false;
		}
	}
	//вывести на экран все значения, упорядоченные по ключу  
	bool show_metr() {
		try {
			for each (std::pair<int, std::pair<int, int>> currentPair in associatedArray)
			{
				std::cout << currentPair.first << ": " << currentPair.second.first << ", " << currentPair.second.second << std::endl;
			}
			return true;
		}
		catch (...) {
			return false;
		}
	}
	//вычислить вспомогательную метрику: возвращает сумму времени ожидания и времени отклика для данного ключа.
	int count_cometr(int key) {
		return associatedArray[key].first + associatedArray[key].second;
	}
};

MetricRegister* MetricRegister::p_instance;
SingletonDestroyer MetricRegister::destroyer;
MetricRegister* SingletonDestroyer::p_instance;