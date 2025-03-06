#include <iostream>
#include <random>  // 更現代的隨機數產生方式
using namespace std;
int social=0,ambition=0,strategy=0,emperor=0,interaction=0,safety=0;
bool E=false;
//場景
void scene (int run)
{
	switch(run) 
	{
		case 0:
        	cout << "在這個充滿陰謀與權謀的古代宮廷中，你是一位想藉由進宮而達成夢想的新人。隨著皇帝登基，宮中的各路勢力也開始蠢蠢欲動。每一位宮女、太監、甚至嬪妃，無論是身處高位還是低位，都在為權力而爾虞我詐。在這個權力的漩渦中，是依附於某個勢力，還是挑戰權威，爭取一席之地？\n";
        	cout << "在古代宮廷中，你需要運用智慧與勇氣，在宮廷中步步為營，結交盟友，並小心應對那些在背後操控一切的權力人物。每一個選擇，無論是愛恨情仇，還是忠誠背叛，都將決定你在這個華麗但危險的宮廷中的命運。\n";
        	cout << "請注意，在這個世界任何問題都將劇烈影響你的未來，再送出回答之前請仔細檢查是否有1.多餘的符號(例如: ，。 .) 2.超過選項之數字(例如選項為1-4，卻回答6)，若不幸發生，可能會有意想不到且危險的後果在等待著你...(例如: ，。 .)，若不幸發生，可能會有意想不到且危險的後果在等待著你...\n";
        	cout << "輸入1-4其中一個數字以繼續遊戲...\n"; 
			break;
    	case 1:
        	cout << "在這座宏偉的宮殿中，有無數種途徑可以進入，選擇不同的方式將決定你在宮中的身份和命運。\n";
        	cout << "1.宮女:低地位，需靠機會晉升，生存能力強\n";
    		cout << "2.貴族小姐:初期即備受矚目，但易成為爭鬥目標\n";
    		cout << "3.答應:直接參與後宮爭鬥，但缺乏背景\n";
    		break;
    	case 2: 
        	cout << "入宮後第一件事是？\n";
        	cout << "對於初入宮廷的你，這是一個陌生且充滿挑戰的環境。對宮中的禮儀、規矩和權力結構完全陌生。每個動作、言談舉止，都有可能影響你的未來。在做出每個決定之前，請仔細想想如何達成美滿的目標。\n";
    		cout << "1.低調行事，避免捲入各黨鬥爭。(但會大幅影響你受寵的機會)\n";
    		cout << "2.積極巴結宮中權貴，找對高位者，你的得勢會極快。(在這當中可能會大量樹敵)\n";
    		cout << "3.依靠太監、宮女情報網，消息靈通，遇到事情時能預先做打算，以防遭人陷害。(但地位難以提升，被揭發時無人能當靠山)\n";
    		cout << "4.靠自身才藝吸引皇上，和他搞好關係直接影響到你的地位和未來發展。有提升成為寵妃的機率及升位快速。(得寵有風險，競爭激烈)\n"; 
    		break;
		case 3: 
    		cout << "與誰搞好關係？\n";
        	cout << "在宮廷中，建立良好的關係對於生存和發展至關重要。\n";
    		cout << "1.太監、宮女: 通常有著深入的內部關係和情報來源。\n";
    		cout << "2.權臣: 為你提供更多的機會，並且讓你在權力鬥爭中站穩腳步。這些人物的支持往往能為你帶來穩固的後盾。\n";
    		cout << "3.嬪妃: 她們的權力與影響力不亞於君王。與她們建立良好關係，對於保護自己的安全、爭取機會都至關重要。\n";
    		cout << "4.皇帝: 宮中最大的權力者，將會直接影響你未來的地位及處境。\n"; 
    		break;
		case 4: 
    		cout << "一位嬪妃拉攏你站隊，你選擇？\n";
        	cout << "一位嬪妃拉攏你站隊，這無疑是一個極具風險但也充滿潛力的機會。在這樣的情況下，你需要仔細考慮來決定是否加入她的陣營。\n";
    		cout << "1.加入\n";
    		cout << "2.拒絕\n";
    		cout << "3.觀望\n";
    		cout << "4.出賣她\n"; 
    		break;
		case 5: 
    		cout << "皇帝突然對你有興趣，你的態度？\n";
        	cout << "這天你在御花園(地圖，從宮殿中走到御花園)悠閒地散步，也許是欣賞花園中的美景，也或許是排解心中的鬱悶。皇帝那天其實也在花園，但距離隔著太遠你並未發現，皇帝從遠處看到身穿一襲紫色紗裙的你，竟對你產生興趣來。而你的態度將影響皇上對你的態度。\n";
    		cout << "1.主動接近\n";
    		cout << "2.若即若離\n";
    		cout << "3.拒絕，保持距離，做自己\n";
    		cout << "4.試圖謀求更高地位\n"; 
    		break;
		case 6: 
    		cout << "敵人開始針對你，你如何反擊？\n";
    		cout << "1.忍耐\n";
    		cout << "2.主動出擊\n";
    		cout << "3.聯合其他嬪妃\n";
    		cout << "4.討好皇后\n"; 
    		break;
		case 7: 
    		cout << "皇帝賜給你一個機會(晉升/封賞)，但有代價，你接受嗎?\n";
    		cout << "1.接受\n";
    		cout << "2.拒絕\n";
    		cout << "3.謀求更大利益\n"; 
    		break;
		case 8: 
    		cout << "皇帝身體不適，你有機會影響皇儲，你決定?\n";
    		cout << "1.支持原太子\n";
    		cout << "2.支持自己兒子\n";
    		cout << "3.聯合當權宰相\n";
    		cout << "4.靜觀其變\n"; 
    		break;
		case 9: 
    		cout << "你面臨生死決策，是否願意放棄權力?\n";
    		cout << "1.是，在宮廷內找生路\n";
    		cout << "2.是，嘗試逃離\n";
    		cout << "3.否，抗爭到底\n"; 
    		break;
		default: 
			cout << "來人，拖出去，斬了!";
			E=true;
	}
}
//選項1
void option_A (int run)
{
	 switch(run) 
	{
		case 0:
			break;
		case 1:
      		cout << "你是出生於鄭州的平民之女，被選入宮服侍\n";
      		strategy+=1;
      		break;
		case 2: 
			strategy+=1;
			social-=1;
			safety+=1; 
			break;
		case 3: 
			strategy+=1;
			social+=1;
			safety-=1; 
			break;
		case 4:
		    cout << "你與後宮嬪妃的關係更緊密了，這也增加你的社交能力，但由於加入陣營造成極大的風險，你有點不太安全...\n";
			interaction+=1;
			social+=1;
			safety-=1; 
			break;
		case 5:
		    cout << "皇帝對你的主動感到好奇，你已占據他心裡的一席之地!但小心其他宮廷勢力與忌妒者對你產生敵意，他們正在視你為威脅。\n";
			emperor+=2;
			ambition+=1;
			safety-=1;
			break;
		case 6:
		    cout << "也許是個好決定呢?你避免了與敵人的正面衝突，這次的決定也使你暫時保護了自身安全。\n";
		    cout << "但這終究無法解決問題，你被視為軟弱的人，原想與你結盟的嬪妃對你保持觀望。\n";
			social-=1;
			ambition-=1;
			strategy+=1;
			safety+=1;
			break;
		case 7:
		    cout << "你接下這困難的任務，我佩服你的勇氣，但你也太衝動了!林貴人最後在你的幫助下成功誕下龍子，皇上龍心大悅!\n";
		    cout << "哇!你現在可是皇上的當紅炸子雞，受到一堆人的忌妒也是很合理的...\n";
			emperor+=2;
			ambition+=2;
			strategy-=1;
			safety-=2; 
			break;
		case 8: 
			if (social>=4&&ambition>=4&&strategy>=4)
			{
				cout << "皇后";
				E=true;

			}
			else if (social>=4&&ambition>=4&&strategy<4)
			{
				cout << "寵妃";
				E=true;
			}
			else 
			{
			 	cout << "平平無奇";
			 	E=true;
			} 
			break;
		case 9: 
			cout << "奴婢"; 
			break;
		default:
			cout << "來人，拖出去，斬了!";
			E=true;
	}
}
//選項2
void option_B (int run)
{
	 switch(run) 
	{
		case 0:
			break;
		case 1:
      		cout << "你是西京洛陽皇親國戚之女，家族背景顯赫\n";
      		social+=1;
      		break;
		case 2: 
			ambition+=1;
			interaction+=1;
			social+=1;
			safety-=2; 
			break;
		case 3: 
			ambition+=1;
			interaction+=1;
			safety-=1; 
			break;
		case 4:
		    cout << "你拒絕了嬪妃的邀請，這使得你與嬪妃們的關係惡化，但因為沒有加入陣營，降低了風險，使得你較為安全。\n";
		    cout << "而皇帝也欣賞你的清高，增加對你的好感!\n";
			interaction-=1;
			social-=1;
			safety+=1; 
			emperor+=1;
			break;
		case 5:
		    cout << "若即若離的態度激起了皇上的征服慾(?)，這也證明了你的策略十分成功!" << endl;
			emperor+=1;
			strategy+=1;
			break;
		case 6:
		    cout << "勇氣的考驗!你快速扭轉對方對你的壓制，贏得一些人的支持，但也得罪了高貴妃陣營的嬪妃們。\n";
		    cout << "看他們近日動作頻頻，不知又是要擊垮誰，當然你也不例外。\n";
			social+=1;
			ambition+=1;
			interaction-=1;
			safety-=1;
			break;
		case 7:
		    cout << "皇帝被你拒絕感到不滿，決定藉此削弱你的地位，你降位為常在。雖然我不是數學家，但這聽起來不太妙對吧?\n";
		    cout << "別擔心，塞翁失馬焉知非福，你反而不再受到其他人的忌妒，能夠自在的生活!\n";
			emperor-=1;
			ambition-=2;
			strategy+=1;
			safety+=1; 
			break;
		case 8: 
		{
			random_device rd;  // 真正的隨機數種子
    		mt19937 gen(rd()); // 產生隨機數引擎
    		uniform_int_distribution<int> dist(1, 100);  // 產生 1~100 之間的數字

    		int chance = dist(gen);  // 抽取隨機數
    		if (chance <= 30){
    			
			}else 
			{
        		cout << "你失敗了...\n";
    		}
    		break;
		}
		case 9:
			if (safety>=4)
			{
				cout << "離宮，平靜的生活\n";
				E=true;
			}
			else
			{
				cout << "宮鬥失敗死亡\n";
				E=true;
			}
			break;
		default:
			cout << "來人，拖出去，斬了!";
			E=true;
	}
}
//選項3
void option_C (int run)
{
	 switch(run) 
	{
		case 0:
			break;
		case 1:
      		cout << "你是宮中的初級嬪妃，因才貌而入宮\n";
      		ambition+=1;
      		break;
		case 2: 
			strategy+=1;
			social+=1;
			break;
		case 3: 
			social+=1;
			strategy+=1;
			break;
		case 4:
		    cout << "選擇觀望使你大幅減少加入陣營後可能會遇到的權力鬥爭\n";
			safety+=2; 
			break;
		case 5:
		    cout << "看起來你對爭寵沒什麼興趣呢!保持距離使你大程度上的維持你的生命安全，但皇上對你遠離他的態度感到不滿，請想想如何重新擄獲他的心吧!\n";
			ambition-=1;
			emperor-=2;
			safety+=2;
			break;
		case 6:
		    cout << "你真是個社交手腕大師!\n";
		    cout << "你形成強大的聯盟，集結多人的支持與資源，誰還能是你的對手!\n";
			social+=1;
			strategy+=1;
			break;
		case 7: 
		{
			random_device rd;  // 真正的隨機數種子
    		mt19937 gen(rd()); // 產生隨機數引擎
    		uniform_int_distribution<int> dist(1, 100);  // 產生 1~100 之間的數字

    		int chance = dist(gen);  // 抽取隨機數
    		if (chance <= 33)
			{ 
    			cout << "皇上:女人你成功吸引了我的注意，朕答應你事成後，必將重重有賞。\n";
    			cout << "哇賽!皇上答應了ㄟ!你的談判手段太高明了，多麼令人稱羨的膽量。\n";
    			cout << "升上貴妃的你獲得崇高的地位與權力，先前欺負妳的嬪妃都急著與你打好關係，你已是一人之下，萬人之上!\n";
    			social+=1;
    			ambition+=2;
    			strategy+=2;
    			emperor+=1;
    			interaction+=1;
    			safety+=2;
    		}
			else
			{
        		cout << "皇上:你哪來的資本與朕談判!\n";
        		cout << "皇帝認為你無理取鬧，你遭到後宮嬪妃們的譏笑，高貴妃心想，現在是最佳的時機，是時候除掉你了，快想想怎麼拯救自己吧!\n";
        		social-=1;
        		interaction-=2;
        		safety-=1;
    		} 
			break;
		}
		case 8: 
    		if (interaction>=5)
			{
				cout << "皇后";
				E=true;
			}
			else 
			{
		 		cout << "被打入冷宮";
	 			E=true;
			} 
			break;
		case 9:
		{
			random_device rd;  // 真正的隨機數種子
    		mt19937 gen(rd()); // 產生隨機數引擎
    		uniform_int_distribution<int> dist(1, 100);  // 產生 1~100 之間的數字

    		int chance = dist(gen);  // 抽取隨機數
    		if (chance<=40)
    		{	
    			if (emperor>=4)
				{
					cout << "寵妃";
					E=true;
				}
				else 
				{
			 		cout << "被打入冷宮";
			 		E=true;
				} 
			}
			else
			{
				cout << "宮鬥失敗死亡";
				E=true; 
			}
			break;
		}
		default:
			cout << "來人，拖出去，斬了!";
			E=true;
	}
}
//選項4
void option_D (int run)
{
	 switch(run) 
	{
		case 0:
			break;
		case 2: 
			emperor+=1;
			safety-=1; 
			break;
		case 3: 
			emperor+=1;
			safety-=1;  
			break;
		case 4: 
    	{
			random_device rd;  // 真正的隨機數種子
    		mt19937 gen(rd()); // 產生隨機數引擎
    		uniform_int_distribution<int> dist(1, 100);  // 產生 1~100 之間的數字

    		int chance = dist(gen);  // 抽取隨機數
    		if (chance<=50)
    		{
    			cout << "皇帝對於你維護宮中的正義感到佩服，對你的好感值，你的勇氣也證明了你聰明睿智的策略手段以及雄厚的野心\n";
    			emperor+=2;
    			ambition+=2;
    			strategy+=2;
			}
			else
			{
				cout << "你的社交手段太糟糕了!出賣貴妃使你遭到孤立，你與嬪妃們的關係惡化，請小心日後他們得針對，你的處境岌岌可危!\n";
				interaction-=2;
				social-=2;
				safety-=1;
			}
			break;
    	}
		case 5: 
		{
			if (emperor>=2)
			{
				cout << "皇帝心想:我已經很久沒看過這麼有個性的女子了，真是太酷了，朕十分喜歡!\n";
				cout << "你對高位強烈渴望展現出你雄厚的野心以及卓越的策略!真是個聰明至極的決定!\n";
        emperor+=1;
				ambition+=2;
			}
			else
			{
				random_device rd;
				mt19937 gen(rd());
				uniform_int_distribution<int> dist(1,100);
			
				int chance = dist(gen);
				if (chance<=33)
				{
					cout << "皇帝心想:我已經很久沒看過這麼有個性的女子了，真是太酷了，朕十分喜歡!";
					cout << "你對高位強烈渴望展現出你雄厚的野心以及卓越的策略!真是個聰明至極的決定!";
					emperor+=1;
					ambition+=2;
					strategy+=1;
				}
				else
				{
					cout << "天啊!你看看你做了什麼!";
					cout << "爭取更高位的過程中，你引發了多場的對立和競爭，引起皇帝和貴族們的不滿，你遭到排擠與針對!";
					cout << "請快救救自己吧!";
					safety-=2;
					emperor-=1;
				}
			}
			break;
		}
		case 6: 
	    {
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<int> dist(1,100);
			
			int chance = dist(gen);
			if (chance<=40)
			{
				cout << "你獲得了他的庇護，得到更多的資源與支持，你可以計畫接下來的計謀了!\n";
				safety+=1;
				ambition+=1;
				strategy+=1;
				social+=1;
			}
			else
			{
				interaction-=1;
				safety-=1;
				social-=1;
			}
			break;
	    }
		case 8: 
	    {
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<int> dist(1,100);
			
			int chance = dist(gen);
			if (chance<=50)
			{
				if (strategy>=4)
				{
				 	cout << "皇后";
				 	E=true;
				} 
				else
				{
				 	cout << "寵妃";
				 	E=true;
				} 
			}
			else
			{
				cout << "平平無奇";
				E=true;
			}
			break;
	    }
		default:
			cout << "來人，拖出去，斬了!";
			E=true;
	}
}

int main() {
    int n, run = 0;

	while (E==false)
	{
        scene(run);
        cin >> n;

        if (n == 1)
            option_A(run);
        else if (n == 2)
            option_B(run);
        else if (n == 3)
            option_C(run);
        else if (n == 4)
            option_D(run);
        else {
              cout << "來人，拖出去，斬了!\n";
              cout << "...再給你一次機會，請謹慎回答...\n";
              continue;
        }
        
        run++;
    }

    return 0;
}
