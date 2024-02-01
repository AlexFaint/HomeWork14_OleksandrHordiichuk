#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector <int> MaxDamage(const vector <float>& HealthChange);
vector <int>  MinDamage(const vector <float>& HealthChange);
vector <int> HealIndex(const vector <float>& HealthChange);
float Overall(const vector <float>& VariableOfHeealth, string HealDamage);
vector <int> NoDamage(const vector <float>& HealthChange);



int main()
{
	int Input = 0;
	float Damage = 0;	
	
	vector <float> HealthChangeList = {35,48,35,13,-8,-15,-12,0,18,0,13,48};

	while (true)
	{
		cout << "Press to chose: " << endl;
		cout << "1-Enter Damage:" << endl;
		cout << "2-What Index MaxDamage index" << endl;
		cout << "3-What Index MinDamage index" << endl;
		cout << "4-What Index Heal index" << endl;
		cout << "5-Amount of heal/damage" << endl;
		cout << "6-Pacifist damage" << endl;


		cin >> Input;

		switch (Input)
		{
		case 1:
		{
			cout << "EnterDamage: ";
			cin >> Damage;
			
			HealthChangeList.push_back(Damage);


			cout << "DamageList: ";
			for (float element : HealthChangeList)
			{
				cout << element << ", ";
			}
			cout << endl;
			
			break;
		}
		case 2:
		{
			vector <int> MaxIndex = MaxDamage(HealthChangeList);

			cout << "Max Damage index: ";
			for (int index : MaxIndex)
			{
				cout << index << ", ";
			}
			cout << endl;
			break;
		}
		case 3:
		{
			vector <int> MinIndex = MinDamage(HealthChangeList);

			cout << "Min Damage index: ";
			for (int index : MinIndex)
			{
				cout << index << ", ";
			}
			cout << endl;
			break;			
		}
		case 4:
		{
			vector <int> HealIndexNum = HealIndex(HealthChangeList);

			cout << "Heal index :";
			for (int index : HealIndexNum)
			{
				cout << index << ", ";
			}
			cout << endl;
			break;
		}
		case 5:
		{
			string HealDamage;
			cout << "(Heal) of (Damage) you try find ? " << endl;
			cin >> HealDamage;

			float OverallHeealthChange = Overall(HealthChangeList, HealDamage);

			cout << "Overall: " << OverallHeealthChange << endl;

			break;
		}
		case 6:
		{
			vector <int> PacifistIndex = NoDamage(HealthChangeList);
			cout << "No damage index :";
			for (int index : PacifistIndex)
			{
				cout << index << ", ";
			}
			cout << endl;
			break;
		}
		default:
			break;
		}		
				
	}	
	
	return 0;
}

vector <int> MaxDamage(const vector <float>& HealthChange)
{
	vector <int> IndexMaxDamageList;

	if (!HealthChange.empty())
	{
		float MaxValue = *max_element(HealthChange.begin(), HealthChange.end());

		for (int i = 0; i < HealthChange.size(); ++i) {
			if (HealthChange[i] == MaxValue) {
				IndexMaxDamageList.push_back(i + 1);
			}
		}
	}
	return IndexMaxDamageList;
}

vector <int>  MinDamage(const vector <float>& HealthChange)
{
	vector <int> IndexMinDamageList;

	auto MinValue = min_element(HealthChange.begin(), HealthChange.end(), [](float a, float b)
		{
			return a > 0 && (b <= 0 || a < b);
		});

	if (MinValue != HealthChange.end())
	{
		float IndexMinDamageValues = *MinValue;

		for (int i = 0; i < HealthChange.size(); ++i)
		{
			if (HealthChange[i] == IndexMinDamageValues)
			{
				IndexMinDamageList.push_back(i + 1);
			}
		}
	}
	return IndexMinDamageList;
}

vector <int> HealIndex(const vector <float>& HealthChange)
{
	vector <int> IndexHealList;

	for (int i = 0; i < HealthChange.size(); ++i)
	{
		if (HealthChange[i] < 0)
		{
			IndexHealList.push_back(i + 1);
		}
	}

	return IndexHealList;
}

float Overall(const vector <float>& VariableOfHeealth, string HealDamage)
{
	float OverallHealthChange = 0;

	for (float value : VariableOfHeealth)
	{
		if ((HealDamage == "Heal" || HealDamage == "heal") && value < 0)
		{
			OverallHealthChange = OverallHealthChange - value;
		}
		else if ((HealDamage == "Damage" || HealDamage == "damage") && value > 0)
		{
			OverallHealthChange = OverallHealthChange + value;
		}
	}
	return OverallHealthChange;
}

vector <int> NoDamage(const vector <float>& HealthChange)
{
	vector <int> NoDamageIndex;

	for (int i = 0; i < HealthChange.size(); ++i)
	{
		if (HealthChange[i] == 0)
		{
			NoDamageIndex.push_back(i + 1);
		}
	}
	return NoDamageIndex;
}