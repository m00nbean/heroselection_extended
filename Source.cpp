#ifndef heroesStruct
#include "heroesStruct.h"
#endif // !heroseStruct

#include<iostream>
#include<cstring>
#include <algorithm>




int talentSum(hero arr[], int size, hero::talent_id t_id);

bool IsHeroPicked(hero allPicked[], int sizeAll, int position);




int main()
{
	using namespace std;

	srand(time(NULL));


	int present = 0;
	int control1 = 0, controlCount = 0;
	int support1 = 0, supportCount = 0;
	int dur2 = 0, durCount = 0;
	int carry1 = 0, carryCount = 0;
	for (int i = 0; i < poolSize; i++)    //подсчет кол-ва героев, поддерживающий бота
	{
		if (heropool[i].inbot == true)
			++present;
	}
	hero* CurrentHeroPool = new hero[present];      //выделение массива для всех героев под бота
	int presentCount = 0;
	for (int i = 0; i < present; i++)				//заполнение массива всех героев бота
	{
		if (heropool[i].inbot == true)
		{
			CurrentHeroPool[presentCount] = heropool[i];
			++presentCount;
		}
	}

	for (int i = 0; i < present; i++)    //подсчет кол-ва героев, контроль 1+
	{
		if (CurrentHeroPool[i].control > 0)
			++control1;
	}

	hero* PoolControl1 = new hero[control1];

	for (int i = 0; i < present && controlCount < control1; i++)				//заполнение массива героев контроль 1+
	{
		if (CurrentHeroPool[i].control > 0)
		{
			PoolControl1[controlCount] = CurrentHeroPool[i];
			++controlCount;
		}
	}

	for (int i = 0; i < present; i++)    //подсчет кол-ва героев, саппорт 1+
	{
		if (CurrentHeroPool[i].support > 0)
			++support1;
	}

	hero* PoolSupport1 = new hero[support1];

	for (int i = 0; i < present && supportCount < support1; i++)				//заполнение массива героев саппорт 1+
	{
		if (CurrentHeroPool[i].support > 0)
		{
			PoolSupport1[supportCount] = CurrentHeroPool[i];
			supportCount++;
		}
	}

	for (int i = 0; i < present; i++)    //подсчет кол-ва героев, стойкость 2+
	{
		if (CurrentHeroPool[i].durabil > 1)
			++dur2;
	}

	hero* PoolDur1 = new hero[dur2];

	for (int i = 0; i < present && durCount < dur2; i++)				//заполнение массива героев стойкость 2+
	{
		if (CurrentHeroPool[i].durabil > 0)
		{
			PoolDur1[durCount] = CurrentHeroPool[i];
			durCount++;
		}
	}

	for (int i = 0; i < present; i++)    //подсчет кол-ва героев, керри 1+
	{
		if (CurrentHeroPool[i].carry > 0)
			++carry1;
	}

	hero* PoolCarry1 = new hero[carry1];

	for (int i = 0; i < present && carryCount < carry1; i++)				//заполнение массива героев керри 1+
	{
		if (CurrentHeroPool[i].carry > 0)
		{
			PoolCarry1[carryCount] = CurrentHeroPool[i];
			carryCount++;
		}
	}

	while(true)
	{
	


	//стадия пика

	cout << "Enter number of players in both teams (example: 1 2):";
	int playersGood = 0;
	int playersBad = 0;
	cin >> playersGood >> playersBad;
	while (playersGood < 0 || playersGood>5 || playersBad < 0 || playersBad>5)
	{
		cout << "\nWrong number of players!\n";
		cout << "Enter again: ";
		cin >> playersGood >> playersBad;
	}

	while (cin.fail())
	{
		std::cin.clear(); 
		std::cin.ignore(32767, '\n'); 
		cout << "\nSomething went wrong. Try again!\n ";
		cin >> playersGood >> playersBad;
	}
	
	string botsGood = " ", botsBad = " ";
	hero heroesGood[5] = { temp,temp,temp,temp,temp };
	hero heroesBad[5] = { temp,temp,temp,temp,temp };
	hero allPicked[10] = { temp,temp,temp,temp,temp ,temp,temp,temp,temp,temp };
	if (playersGood < 5)												//Выбор Контроля для 1 команды
	{
		do
		{
			int heroesGoodTemp1 = rand() % controlCount;
			heroesGood[0] = PoolControl1[heroesGoodTemp1];
			allPicked[0] = PoolControl1[heroesGoodTemp1];
		} while (heroesGood[0].carry<2);
		
	}
	if (playersGood < 4)												//выбор саппорта для 1 команды
	{
		int heroesGoodTemp2 = 0;
		do
		{
			heroesGoodTemp2 = rand() % supportCount;
			heroesGood[1] = PoolSupport1[heroesGoodTemp2];
			allPicked[1] = PoolSupport1[heroesGoodTemp2];
		} while (IsHeroPicked(allPicked, 10, 1) == true);


	}
	if (playersGood < 3)												//Выбор танка для 1 команды
	{
		int heroesGoodTemp3 = 0;
		do
		{
			heroesGoodTemp3 = rand() % durCount;
			heroesGood[2] = PoolDur1[heroesGoodTemp3];
			allPicked[2] = PoolDur1[heroesGoodTemp3];
		} while (IsHeroPicked(allPicked, 10, 2) == true);

	}
	if (playersGood < 2)
	{
		int sumSupp = talentSum(heroesGood, 5, hero::talent_id::e_support);						//Выбор 4 бота 1 команды
		int sumControl = talentSum(heroesGood, 5, hero::talent_id::e_control);
		int heroesGoodTemp4 = 0;
		if (sumControl < 3)																		//Выбор контроля, если сумма конт<3
		{
			do
			{
				heroesGoodTemp4 = rand() % controlCount;
				heroesGood[3] = PoolControl1[heroesGoodTemp4];
				allPicked[3] = PoolControl1[heroesGoodTemp4];
			} while ((IsHeroPicked(allPicked, 10, 3)) == true);

		}
		else if (sumSupp < 3)																//Выбор саппорта, если сумма сапп<0
		{
			do
			{
				heroesGoodTemp4 = rand() % supportCount;
				heroesGood[3] = PoolSupport1[heroesGoodTemp4];
				allPicked[3] = PoolSupport1[heroesGoodTemp4];
			} while (IsHeroPicked(allPicked, 10, 3) == true);

		}
		else
		{
			do
			{
				heroesGoodTemp4 = rand() % carryCount;										//Выбор керри1, если сапп и контроль >=3
				heroesGood[3] = PoolCarry1[heroesGoodTemp4];
				allPicked[3] = PoolCarry1[heroesGoodTemp4];
			} while (IsHeroPicked(allPicked, 10, 3) == true);


		}
		sumSupp, sumControl = 0;

	}
	if (playersGood == 0)													//Выбор 5 бота 1 команды
	{
		int heroTemp5 = 0;
		hero sumHero = temp;																//временный герой для подсчета суммы характеристик команды
		sumHero.carry = talentSum(heroesGood, 5, hero::talent_id::e_carry);
		sumHero.support = talentSum(heroesGood, 5, hero::talent_id::e_support);
		sumHero.control = talentSum(heroesGood, 5, hero::talent_id::e_control);
		sumHero.nuker = talentSum(heroesGood, 5, hero::talent_id::e_nuker);
		sumHero.durabil = talentSum(heroesGood, 5, hero::talent_id::e_durabil);
		sumHero.init = talentSum(heroesGood, 5, hero::talent_id::e_init);

		int talents[] = { sumHero.carry ,sumHero.support ,sumHero.control ,sumHero.nuker ,sumHero.durabil ,sumHero.init };
		int talentArrRange = sizeof(talents) / sizeof(talents[0]);
		sort(talents, talents + talentArrRange);
		if (talents[0] == sumHero.carry)													//Выбор керри 2+
		{
			do
			{
				heroTemp5 = rand() % carryCount;
				heroesGood[4] = PoolCarry1[heroTemp5];
				allPicked[4] = PoolCarry1[heroTemp5];
			} while (IsHeroPicked(allPicked, 10, 4) == true || heroesGood[4].carry <= 2);
		}
		else if (talents[0] == sumHero.support)												//Выбор саппорт 2+
		{
			do
			{
				heroTemp5 = rand() % supportCount;
				heroesGood[4] = PoolSupport1[heroTemp5];
				allPicked[4] = PoolSupport1[heroTemp5];
			} while (IsHeroPicked(allPicked, 10, 4) == true || heroesGood[4].support <= 2);
		}
		else if (talents[0] == sumHero.control)
		{
			do
			{
				heroTemp5 = rand() % controlCount;
				heroesGood[4] = PoolControl1[heroTemp5];
				allPicked[4] = PoolControl1[heroTemp5];
			} while (IsHeroPicked(allPicked, 10, 4) == true || heroesGood[4].control <= 2);
		}
		else if (talents[0] == sumHero.nuker)
		{
			do
			{
				heroTemp5 = rand() % present;
				heroesGood[4] = CurrentHeroPool[heroTemp5];
				allPicked[4] = CurrentHeroPool[heroTemp5];
			} while (IsHeroPicked(allPicked, 10, 4) == true || heroesGood[4].nuker <= 2);
		}
		else if (talents[0] == sumHero.durabil)
		{
			do
			{
				heroTemp5 = rand() % durCount;
				heroesGood[4] = PoolDur1[heroTemp5];
				allPicked[4] = PoolDur1[heroTemp5];
			} while (IsHeroPicked(allPicked, 10, 4) == true || heroesGood[4].durabil <= 2);
		}
		else
			do
			{
				heroTemp5 = rand() % present;
				heroesGood[4] = CurrentHeroPool[heroTemp5];
				allPicked[4] = CurrentHeroPool[heroTemp5];
			} while (IsHeroPicked(allPicked, 10, 4) == true || heroesGood[4].init <= 2);

	}



	//Пик второй команды

	if (playersBad < 5)												//Выбор Контроля для 2 команды
	{
		do
		{
			int heroesBadTemp1 = rand() % controlCount;
			heroesBad[0] = PoolControl1[heroesBadTemp1];
			allPicked[5] = PoolControl1[heroesBadTemp1];
		} while ((IsHeroPicked(allPicked, 10, 5) == true)|| heroesBad[0].carry<2);
	}
	if (playersBad < 4)												//выбор саппорта для 2 команды
	{
		int heroesBadTemp2 = 0;
		do
		{
			heroesBadTemp2 = rand() % supportCount;
			heroesBad[1] = PoolSupport1[heroesBadTemp2];
			allPicked[6] = PoolSupport1[heroesBadTemp2];
		} while (IsHeroPicked(allPicked, 10, 6) == true);


	}
	if (playersBad < 3)												//Выбор танка для 2 команды
	{
		int heroesBadTemp3 = 0;
		do
		{
			heroesBadTemp3 = rand() % durCount;
			heroesBad[2] = PoolDur1[heroesBadTemp3];
			allPicked[7] = PoolDur1[heroesBadTemp3];
		} while (IsHeroPicked(allPicked, 10, 7) == true);

	}
	if (playersBad< 2)
	{
		int sumSupp = talentSum(heroesBad, 5, hero::talent_id::e_support);						//Выбор 4 бота 2 команды
		int sumControl = talentSum(heroesBad, 5, hero::talent_id::e_control);
		int heroesBadTemp4 = 0;
		if (sumControl < 3)																		//Выбор контроля, если сумма конт<3
		{
			do
			{
				heroesBadTemp4 = rand() % controlCount;
				heroesBad[3] = PoolControl1[heroesBadTemp4];
				allPicked[8] = PoolControl1[heroesBadTemp4];
			} while (IsHeroPicked(allPicked, 10, 8) == true);

		}
		else if (sumSupp < 3)																//Выбор саппорта, если сумма сапп<0
		{
			do
			{
				heroesBadTemp4 = rand() % supportCount;
				heroesBad[3] = PoolSupport1[heroesBadTemp4];
				allPicked[8] = PoolSupport1[heroesBadTemp4];
			} while (IsHeroPicked(allPicked, 10, 8) == true);

		}
		else
		{
			do
			{
				heroesBadTemp4 = rand() % carryCount;										//Выбор керри1, если сапп и контроль >=3
				heroesBad[3] = PoolCarry1[heroesBadTemp4];
				allPicked[8] = PoolCarry1[heroesBadTemp4];
			} while (IsHeroPicked(allPicked, 10, 8) == true);


		}
		sumSupp, sumControl = 0;

	}
	if (playersBad == 0)													//Выбор 5 бота 2 команды
	{
		int heroTemp5 = 0;
		hero sumHero = temp;																//временный герой для подсчета суммы характеристик команды
		sumHero.carry = talentSum(heroesBad, 5, hero::talent_id::e_carry);
		sumHero.support = talentSum(heroesBad, 5, hero::talent_id::e_support);
		sumHero.control = talentSum(heroesBad, 5, hero::talent_id::e_control);
		sumHero.nuker = talentSum(heroesBad, 5, hero::talent_id::e_nuker);
		sumHero.durabil = talentSum(heroesBad, 5, hero::talent_id::e_durabil);
		sumHero.init = talentSum(heroesBad, 5, hero::talent_id::e_init);

		int talents[] = { sumHero.carry ,sumHero.support ,sumHero.control ,sumHero.nuker ,sumHero.durabil ,sumHero.init };
		int talentArrRange = sizeof(talents) / sizeof(talents[0]);
		//sort(talents, talents + talentArrRange);
		
		for (int i = 0; i < talentArrRange; i++)
		{
			if (talents[0] > talents[i])
			{
				talents[0] = talents[i];
			}
		}

		if (talents[0] == sumHero.carry)													//Выбор керри 2+
		{
			do
			{
				heroTemp5 = rand() % carryCount;
				heroesBad[4] = PoolCarry1[heroTemp5];
				allPicked[9] = PoolCarry1[heroTemp5];
			} while (IsHeroPicked(allPicked, 10, 9) == true || heroesBad[4].carry <= 2);
		}
		else if (talents[0] == sumHero.support)												//Выбор саппорт 2+
		{
			do
			{
				heroTemp5 = rand() % supportCount;
				heroesBad[4] = PoolSupport1[heroTemp5];
				allPicked[9] = PoolSupport1[heroTemp5];
			} while (IsHeroPicked(allPicked, 10, 9) == true || heroesBad[4].support <= 2);
		}
		else if (talents[0] == sumHero.control)
		{
			do
			{
				heroTemp5 = rand() % controlCount;
				heroesBad[4] = PoolControl1[heroTemp5];
				allPicked[9] = PoolControl1[heroTemp5];
			} while (IsHeroPicked(allPicked, 10, 9) == true || heroesBad[4].control <= 2);
		}
		else if (talents[0] == sumHero.nuker)
		{
			do
			{
				heroTemp5 = rand() % present;
				heroesBad[4] = CurrentHeroPool[heroTemp5];
				allPicked[9] = CurrentHeroPool[heroTemp5];
			} while (IsHeroPicked(allPicked, 10, 9) == true || heroesBad[4].nuker <= 2);
		}
		else if (talents[0] == sumHero.durabil)
		{
			do
			{
				heroTemp5 = rand() % durCount;
				heroesBad[4] = PoolDur1[heroTemp5];
				allPicked[9] = PoolDur1[heroTemp5];
			} while (IsHeroPicked(allPicked, 10, 9) == true || heroesBad[4].durabil <= 2);
		}
		else
			do
			{
				heroTemp5 = rand() % present;
				heroesBad[4] = CurrentHeroPool[heroTemp5];
				allPicked[9] = CurrentHeroPool[heroTemp5];
			} while (IsHeroPicked(allPicked, 10, 9) == true || heroesBad[4].init <= 2);

	}


	//составление строки консольной команды

	string prephrase = "There is some heroes: ";
	string commands = " ";
	
	for (int i = 0; i < 10; i++)
	{
		if (allPicked[i].hero_id != temp.hero_id)
		{
			commands += allPicked[i].command;
			commands += ", ";
		}
	}
	if (commands.size() > 0)
	{
		commands.erase(commands.size() - 2);
		
	}

	string prefase = "dota_bot_force_pick ";
	cout << prephrase << "\n\n";
	cout << prefase<<commands << "\n\n";

	/*bool finalCheck = false;
	for (int i = 0; i < 10; i++)
	{
		for (int j=0; j < 10; j++)
			if (j != i)
				if (allPicked[i].hero_id == allPicked[j].hero_id && allPicked[i].hero_id != 999)
					finalCheck = true;
	}

	if (finalCheck == true)
		cout << "\n\n\t\tThere is some mistakes!\n\n";*/
}

delete[] CurrentHeroPool;
delete[] PoolControl1;
delete[] PoolSupport1;
delete[] PoolDur1;
delete[] PoolCarry1;

		
		//for (int i = 0; i < 5; i++)
		//{
		//	present = false;
		//	char heroname[20] = " ";
		//	cin.getline(heroname, 20);			//ввод имени героя
		//	for (int j = 0; j < poolSize; j++)
		//	{

		//		if (strcmp(heroname, heropool[j].name) == 0)				//проверка правильности ввода имени
		//		{
		//			heroesInBattle[i] = heropool[j];
		//			present = true;
		//			break;
		//		}

		//	}
		//	if (present == false)
		//	{
		//		cout << "\nIncorrect hero, enter again: ";
		//		i--;
		//	}

		//}

		/*int supp1 = 0;
		int supp2 = 0;
		int supp3 = 0;
		int cont1 = 0;
		int cont2 = 0;
		int cont3 = 0;
		int nuker1 = 0, nuker2 = 0, nuker3 = 0;
		int dur1 = 0, dur2 = 0, dur3 = 0;
		
		for (int i = 0; i < poolSize; i++)
		{
			if (heropool[i].support >= 1)
			{
				++supp1;
				if (heropool[i].support >= 2)
				{
					++supp2;
					if (heropool[i].support >= 3)
						++supp3;
				}
			}
			if (heropool[i].control >= 1)
			{
				++cont1;
				if (heropool[i].control >= 2)
				{
					++cont2;
					if (heropool[i].control >= 3)
						++cont3;
				}
			}
			if (heropool[i].nuker >= 1)
			{
				++nuker1;
				if (heropool[i].nuker >= 2)
				{
					++nuker2;
					if (heropool[i].nuker >= 3)
						++nuker3;
				}
			}
			if (heropool[i].durabil >= 1)
			{
				++dur1;
				if (heropool[i].durabil >= 2)
				{
					++dur2;
					if (heropool[i].durabil >= 3)
						++dur3;
				}
			}
		}*/

		/*cout << "Support:\n" << "Support1: " << supp1 <<
			"\tSupport2: " << supp2 << "\tSupport3: " << supp3;
		cout << "\n\nControl:\n" << "Control1: " << cont1 <<
			"\tControl2: " << cont2 << "\tControl3: " << cont3;
		cout << "\n\nNuker:\n" << "Nuker1: " << nuker1 <<
			"\tNuker2: " << nuker2 << "\tNuker3: " << nuker3;
		cout << "\n\nDurability:\n" << "Dur1: " << dur1 <<
			"\tDur2: " << dur2 << "\tDur3: " << dur3;*/



		/*cout << "There is some heroes: \n\n";
		for (int i = 0; i < 5; i++)
		{
			cout << heroesInBattle[i].command << '\t' << '\n';
		}
		
		


		int sumCarry = 0, sumSupp = 0, sumNuker = 0, sumControl = 0;
		int sumDurabil = 0, sumInit = 0;

		cout << "\n\nHere some team stats: ";*/

		/*sumCarry = talentSum(heroesInBattle, 5, hero::talent_id::e_carry);
		sumSupp = talentSum(heroesInBattle, 5, hero::talent_id::e_support);
		sumNuker = talentSum(heroesInBattle, 5, hero::talent_id::e_nuker);
		sumControl = talentSum(heroesInBattle, 5, hero::talent_id::e_control);
		sumDurabil = talentSum(heroesInBattle, 5, hero::talent_id::e_durabil);
		sumInit = talentSum(heroesInBattle, 5, hero::talent_id::e_init);

		cout << "\nCarry: " << sumCarry << "\tSupport: " << sumSupp
			<< "\nNuker: " << sumNuker << "\tCuntrol: " << sumControl
			<< "\nDurability: " << sumDurabil << "\tInitiation: " << sumInit;
	*/
		cin.get();

	
}



int talentSum(hero arr[],int size,hero::talent_id t_id)
{
	int sum = 0;

	switch (t_id)
	{
	case hero::talent_id::e_carry:
		for (int i = 0; i < size; i++)
		{
			sum += arr[i].carry;
		}
		return sum;
	case hero::talent_id::e_support:
		for (int i = 0; i < size; i++)
		{
			sum += arr[i].support;
		}
		return sum;
	case hero::talent_id::e_nuker:
		for (int i = 0; i < size; i++)
		{
			sum += arr[i].nuker;
		}
		return sum;
	case hero::talent_id::e_control:
		for (int i = 0; i < size; i++)
		{
			sum += arr[i].control;
		}
		return sum;
	case hero::talent_id::e_durabil:
		for (int i = 0; i < size; i++)
		{
			sum += arr[i].durabil;
		}
		return sum;
	case hero::talent_id::e_init:
		for (int i = 0; i < size; i++)
		{
			sum += arr[i].init;
		}
		return sum;
	
	}
	
	return 0;
}




bool IsHeroPicked(hero allPicked[], int sizeAll,int position)
{
	bool isPicked = false;

	
	for (int i = 0; i <=position; i++)
	{
		if (position != i)
		{
			if (allPicked[position].hero_id == allPicked[i].hero_id && allPicked[position].hero_id != temp.hero_id)	//проверка всех героев по id
			{
				isPicked = true;
				break;
			}
		}
	}
	
	return isPicked;
	
}


