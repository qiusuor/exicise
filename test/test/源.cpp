#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/algorithm/string/predicate.hpp>


typedef std::map<std::string, std::string> record_type;
typedef std::vector<std::map<std::string, std::string>> records_type;

class sql {
	const std::string sql_file = "sql.bin";

	records_type read_records() {
		records_type all_records;
		try {
			std::ifstream fin(sql_file, std::ios::binary);
			boost::archive::binary_iarchive iarch(fin);
			iarch >> all_records;
		}
		catch (std::exception &err) {}
		return all_records;
	}

	void write_records(records_type &all_records) {
		std::ofstream fout(sql_file, std::ios::binary);
		boost::archive::binary_oarchive oarch(fout);
		oarch << all_records;
	}

public:
	//remove the sql file
	void clear_sql() {
		remove(sql_file.c_str());
	}

	static void print_records(records_type &records) {
		int index = 0;
		for (auto &item : records) {
			std::cout << index++ << "  ";
			for (auto entry = item.begin(); entry != item.end(); ++entry) {
				std::cout << entry->first << ":" << entry->second << (std::next(entry) != item.end() ? ",\t" : "\n");
			}
		}
	}

	void print() {
		records_type all_records = read_records();
		print_records(all_records);
	}

	void add(records_type &records) {
		records_type all_records = read_records();
		//append to exist data
		all_records.insert(all_records.end(), records.begin(), records.end());
		write_records(all_records);
	}

	template<typename L>
	void del(L filter) {
		auto all_records = read_records();
		records_type results;
		all_records.erase(std::remove_if(all_records.begin(), all_records.end(), filter), all_records.end());
		write_records(all_records);
	}

	template<typename L>
	records_type find(L filter) {
		auto all_records = read_records();
		records_type results;
		auto it = std::copy_if(all_records.begin(), all_records.end(), std::back_inserter(results), filter);
		return results;
	}
};

int main() {
	sql s;
	//debug clear data
	//std::cout << "\n===========�ؽ����ݿ�\n\n";
	//s.clear_sql();
	//����9����¼
	std::cout << "\n===========���������¼\n";
	records_type records_add;
	records_add.insert(records_add.end(), {
		record_type({ { "�༶", "981101" },
		{ "�γ�", "���ݿ�" },
		{ "��ʦ", "����" },
		{ "ѧ��", "98��" },
		{ "ѧ��", "98110101" },
		{ "����", "����" },
		{ "�ɼ�", "99" } }),
		record_type({ { "�༶", "981101" },
		{ "�γ�", "���ݿ�" },
		{ "��ʦ", "����" },
		{ "ѧ��", "98��" },
		{ "ѧ��", "98110102" },
		{ "����", "����" },
		{ "�ɼ�", "59" } }),
		record_type({ { "�༶", "981102" },
		{ "�γ�", "�����" },
		{ "��ʦ", "����" },
		{ "ѧ��", "98��" },
		{ "ѧ��", "98110202" },
		{ "����", "��һһ" },
		{ "�ɼ�", "60" } }),
		record_type({ { "�༶", "981101" },
		{ "�γ�", "�����" },
		{ "��ʦ", "����" },
		{ "ѧ��", "98��" },
		{ "ѧ��", "98110203" },
		{ "����", "����" },
		{ "�ɼ�", "30" } }),
		record_type({ { "�༶", "981101" },
		{ "�γ�", "���ݿ�" },
		{ "��ʦ", "2233" },
		{ "ѧ��", "98��" },
		{ "ѧ��", "98110203" },
		{ "����", "��С��" },
		{ "�ɼ�", "10" } })
	});
	s.add(records_add);
	s.print();

	//���� ���ݿⲻ��������м�¼
	std::cout << "\n===========�������ݿⲻ�������м�¼\n";
	auto filter_find = [](record_type &record) -> bool {
		return record["�γ�"] == "���ݿ�" && stoi(record["�ɼ�"]) < 60;
	};
	auto results = s.find(filter_find);
	sql::print_records(results);

	//ɾ�� ����ͬѧ�����м�¼
	std::cout << "\n===========ɾ������ͬѧ���м�¼\n";
	auto filter_del = [](record_type &record) -> bool {
		return boost::starts_with(record["����"], "��");
	};
	s.del(filter_del);
	s.print();
	system("pause");
	return 0;
}