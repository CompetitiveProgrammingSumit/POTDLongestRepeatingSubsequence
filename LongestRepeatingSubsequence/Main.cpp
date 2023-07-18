#include <iostream>
#include <vector>

class Solution
{
	public:
		int LongestRepeatingSubsequence(std::string str)
		{
			int stringLength = (int)(str.length());
			int maxCount	 = 0;
			std::vector<std::vector<int>> freqVector(stringLength, std::vector<int>(stringLength, 0));
			for (int i = 1; i < stringLength; i++)
			{
				if (str[0] == str[i])
				{
					freqVector[0][i] = 1;
					maxCount		 = 1;
				}
				else
				{
					freqVector[0][i] = freqVector[0][i - 1];
				}
			}
			for (int i = 1; i < stringLength; i++)
			{
				for (int k = 0; k <= i; k++)
				{
					freqVector[i][k] = freqVector[i - 1][k];
				}
				for (int j = i + 1; j < stringLength; j++)
				{
					if (str[i] == str[j])
					{
						freqVector[i][j] = freqVector[i - 1][j - 1] + 1;
						maxCount		 = maxCount < freqVector[i][j] ? freqVector[i][j] : maxCount;
					}
					else
					{
						freqVector[i][j] = std::max(freqVector[i - 1][j], freqVector[i][j - 1]);
					}
				}
			}
			return maxCount;
		}

};

int main()
{
	std::string str;
	std::cin >> str;
	Solution obj;
	int ans = obj.LongestRepeatingSubsequence(str);
	std::cout << ans << "\n";

	return 0;
}





/*
aaptvbifvn
o/p: 2












yvpyruvjhb
o/p: 2
*/