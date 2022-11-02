#include <string>
#include <vector>

using namespace std;
//"aya", "ye", "woo", "ma"
int solution(vector<string> babbling) {
	int answer = 0;

	for (auto s : babbling) {
		string previous = "";
		bool dd = false;

		for (int i = 0; i < s.size(); i++) {

			switch (s[i])
			{
			case 'a':
				if (previous.compare("aya") != 0 && i < s.size() - 2 && s[i + 1] == 'y' && s[i + 2] == 'a') {
					previous = "aya";
					i += 2;
				}
				else
					dd = true;
				break;
			case 'y':
				if (previous.compare("ye") != 0 && i < s.size() - 1 && s[i + 1] == 'e') {
					previous = "ye";
					i++;
				}
				else
					dd = true;
				break;
			case 'w':
				if (previous.compare("woo") != 0 && i < s.size() - 2 && s[i + 1] == 'o' && s[i + 2] == 'o') {
					previous = "woo";
					i += 2;
				}
				else
					dd = true;
				break;
			case 'm':
				if (previous.compare("ma") != 0 && i < s.size() - 1 && s[i + 1] == 'a') {
					previous = "ma";
					i++;
				}
				else
					dd = true;
				break;

			default:
				dd = true;
				break;
			}

			if (dd) break;
		}
		if (dd) dd = false;
		else answer++;
	}

	return answer;
}


//´õ ±ò²ûÇÑ ¹æ¹ý
int solution2(vector<string> babbling) {
	int answer = 0;

	for (string s : babbling)
	{
		int flag = 0; bool j = true;
		for (int i = 0; i < s.length(); i++)
		{
			if (s.substr(i, 3) == "aya" && flag != 1) { flag = 1; i += 2; }
			else if (s.substr(i, 2) == "ma" && flag != 2) { flag = 2; i += 1; }
			else if (s.substr(i, 3) == "woo" & flag != 3) { flag = 3; i += 2; }
			else if (s.substr(i, 2) == "ye" && flag != 4) { flag = 4; i += 1; }
			else { j = false; break; }
		}
		if (j == true) answer++;
	}

	return answer;
}