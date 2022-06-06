#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

struct Examinee {
	string id;
	float grade[11]={0};
};

Examinee readExaminee(string line_inf) {
	stringstream ss(line_inf);
	string temp;
	Examinee student;
	getline(ss, student.id, ','); //đọc id
	getline(ss, temp, ','); //đọc tên
	for (int i = 0; i < 11; i++) {
		getline(ss, temp, ','); // đọc điểm thứ i vào temp
		if (temp == "")
			student.grade[i] = 0;
		else
			student.grade[i] = stof(temp);
	}
	return student;
}

vector<Examinee> readExamineeList(string fname) {
	ifstream fi(fname);
	vector<Examinee> V;
	Examinee student;
	string temp;
	getline(fi, temp); // bỏ qua dòng tiêu đề
	while (!fi.eof()) {
		getline(fi, temp);
		student = readExaminee(temp);
		V.push_back(student);
	}
	fi.close();
	return V;
}

void writeTotal(vector<Examinee> examinee_list, string out_file) {
	ofstream fo(out_file);
	float sum;
	for (int i = 0; i < examinee_list.size(); i++) {
		sum = 0;
		for (int j = 0; j < 11; j++) {
			sum += examinee_list[i].grade[j];
		}
		fo << examinee_list[i].id << "\t" << sum << endl;
	}
	fo.close();
}

int main() {
	vector<Examinee> V = readExamineeList("text.txt");
	writeTotal(V, "result.txt");
	return 0;
}

//struct Examinee
//{
//	string id;
//	float math = 0, literature = 0, physic = 0, chemistry = 0, biology = 0, history = 0, geography = 0, civic_education = 0, natural_science = 0, social_science = 0, foreign_language = 0;
//};
//
//Examinee readExaminee(string line_info) {
//	Examinee examinee;
//	vector<string> lineInfos;
//
//	string lineInfo = "";
//	for (int i = 0; i < line_info.size(); i++) {
//		if (line_info[i] != ',')
//			lineInfo += line_info[i];
//		else
//		{
//			lineInfos.push_back(lineInfo);
//			lineInfo = "";
//		}
//	}
//
//	lineInfos.push_back(lineInfo);
//
//	examinee.id = lineInfos[0];
//	lineInfos[2] != "" ? examinee.math = stof(lineInfos[2]) : examinee.math = 0;
//	lineInfos[3] != "" ? examinee.literature = stof(lineInfos[3]) : examinee.literature = 0;
//
//	lineInfos[4] != "" ? examinee.physic = stof(lineInfos[4]) : examinee.physic = 0;
//	lineInfos[5] != "" ? examinee.chemistry = stof(lineInfos[5]) : examinee.chemistry = 0;
//	lineInfos[6] != "" ? examinee.biology = stof(lineInfos[6]) : examinee.biology = 0;
//
//	lineInfos[7] != "" ? examinee.history = stof(lineInfos[7]) : examinee.history = 0;
//	lineInfos[8] != "" ? examinee.geography = stof(lineInfos[8]) : examinee.geography = 0;
//	lineInfos[9] != "" ? examinee.civic_education = stof(lineInfos[9]) : examinee.civic_education = 0;
//
//	lineInfos[12] != "" ? examinee.foreign_language = stof(lineInfos[12]) : examinee.foreign_language = 0;
//
//	examinee.natural_science = examinee.physic + examinee.chemistry + examinee.biology;
//	examinee.social_science = examinee.history + examinee.geography + examinee.civic_education;
//
//	return examinee;
//}
//
//vector<Examinee> readExamineeList(string file_name) {
//	vector<Examinee> examinee_list = {};
//	ifstream inputFile;
//	inputFile.open(&file_name[0], ios_base::in);
//
//	if (inputFile.is_open()) {
//		string lineInfo = "";
//		getline(inputFile, lineInfo, '\n');
//
//		while (!inputFile.eof()) {
//			getline(inputFile, lineInfo, '\n');
//			Examinee examinee = readExaminee(lineInfo);
//			examinee_list.push_back(examinee);
//		}
//	}
//	else
//		cout << "Error opening file!\n";
//
//	return examinee_list;
//}
//
//void writeTotal(vector<Examinee> examinee_list, string out_file_name) {
//	ofstream outputFile;
//	outputFile.open(&out_file_name[0], ios_base::out);
//
//	if (outputFile.is_open()) {
//		for (auto examinee : examinee_list) {
//			outputFile << examinee.id << " ";
//			outputFile << examinee.math + examinee.literature + examinee.foreign_language + examinee.natural_science + examinee.social_science << "\n";
//		}
//		cout << "Success!\n";
//	}
//	else
//		cout << "Error opening file!\n";
//}
//
//int main() {
//	vector<Examinee> examinee_list = readExamineeList("text.txt");
//	writeTotal(examinee_list, "result.txt");
//	return 0;
//}
