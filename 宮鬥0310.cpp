#include <iostream>
#include <random>  // 更現代的隨機數產生方式
#include <cstdlib>  // system("clear") 或 system("cls")
#include <unistd.h>  // 用於 usleep（Linux/macOS 下）或者 Windows 用 Sleep()
#include <cctype>  // 用於 tolower 函數
using namespace std;
int social=0,ambition=0,strategy=0,emperor=0,interaction=0,safety=0; //將能力值設定在全域變數，以供自訂函式使用，這些數值將影響遊戲結局
bool E=false,F=false; //結束條件判定用
const int MAP_WIDTH = 10;
const int MAP_HEIGHT = 10;
int playerX = 1, playerY = 0;  // 玩家初始位置
char prevTile = '#';  // 記錄玩家上一個位置的地圖元素，以便恢復地圖
// 遊戲地圖，使用不同符號代表不同地形
char map[MAP_HEIGHT][MAP_WIDTH] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', 'C', '#', 'S', '#'},
    {'#', 'T', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', 'S', 'S', 'S', '#', '#', '#', '#'},
    {'T', 'T', '#', '#', '#', '#', '#', '#', 'C', '#'},
    {'#', '#', '#', 'C', 'C', '#', 'T', 'T', '#', '#'},
    {'S', '#', 'T', 'T', '#', '#', '#', 'S', '#', '#'},
    {'S', '#', 'C', '#', '#', '#', '#', '#', '#', 'S'},
    {'#', '#', '#', '#', 'C', 'C', '#', 'S', '#', 'C'},
    {'#', 'C', '#', '#', 'H', '#', '#', '#', '#', '#'}
};
// 顯示地圖，使用 system("clear") 或 system("cls") 來清除畫面
void showMap() {
    #ifdef _WIN32
        system("cls");  // Windows 清屏
    #else
        system("clear"); // Linux/macOS 清屏
    #endif

    cout << "這天，也許是為了欣賞花園中的美景，又或是為了排解心中的鬱悶，你來到了御花園。\n";
    cout << "你在御花園悠閒地散步\n";
    cout << "*請利用鍵盤上W/w、S/s、A/a、D/d進行上下左右移動，從宮殿中走到御花園\n";

    // 顯示地圖元素的標示文字
    cout << "=== 地圖元素說明 ===" << endl;
    cout << "#  - 道路 (Road)" << endl;
    cout << "\033[38;5;8mS  - 石頭 (Stone)\033[0m" << endl; // 石頭為灰色
    cout << "\033[38;5;13mC  - 櫻花 (Cherry)\033[0m" << endl; // 櫻花為粉色
    cout << "\033[38;5;2mT  - 草 (Grass)\033[0m" << endl;   // 草為綠色
    cout << "\033[38;5;11mH  - 御花園 (Herb Garden)\033[0m" << endl; // 御花園為黃色
    cout << "\033[38;5;9mP  - 玩家 (Player)\033[0m" << endl; // 玩家為紅色
    cout << "=====================" << endl;

    // 顯示地圖
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            if (x == playerX && y == playerY) {
                // 設置玩家顏色為紅色
                cout << "\033[38;5;9m" << "P  " << "\033[0m";  // 紅色顯示玩家
            } else {
                // 根據地圖內容顯示不同的字符
                if (map[y][x] == 'S') {
                    cout << "\033[38;5;8m" << "S  " << "\033[0m";  // 石頭顯示灰色
                } else if (map[y][x] == 'C') {
                    cout << "\033[38;5;13m" << "C  " << "\033[0m";  // 櫻花顯示粉色
                } else if (map[y][x] == 'T') {
                    cout << "\033[38;5;2m" << "T  " << "\033[0m";  // 草顯示綠色
                } else if (map[y][x] == 'H') {
                    cout << "\033[38;5;11m" << "H  " << "\033[0m";  // 御花園顯示黃色
                } else if (map[y][x] == '#') {
                    cout << "\033[38;5;7m" << "#  " << "\033[0m";  // 道路顯示灰色
                }
            }
        }
        cout << endl;
    }
}
/*
* 以巢狀迴圈判斷地點，並輸出相應文字。
* 參數:
* int newX - 地圖 x 座標
* int newY - 地圖 y 座標
*/
bool checkCollisionWithObject(int newX, int newY) {
    if (map[newY][newX] == 'S') {
        cout << "這石頭也太硬了" << endl;
        usleep(500000); // 暫停 0.5 秒以顯示訊息
        return true;
    } else if (map[newY][newX] == 'C') {
        cout << "這花兒終於開了，這可真美阿" << endl;
        usleep(500000);
        return true;
    } else if (map[newY][newX] == 'T') {
        cout << "這草多久沒除啦，都長我的腳踝了，等會兒叫小炭子來處理" << endl;
        usleep(500000);
        return true;
    } else if (map[newY][newX] == 'H') {
        cout << "終於到御花園了!" << endl;
        usleep(2000000);
        F=true;
        return false;
    }
    return false;
}
/*
* 以巢狀迴圈判斷與記錄使用者上/下/左/右，並有地圖邊界判斷，若撞牆會輸出提示文字並停留在原地。
* 參數:char move - 使用者選擇的移動方向
*/
void handleMovement(char move) {
    int newX = playerX, newY = playerY;

    move = tolower(move);  // 將輸入字母轉為小寫

    if (move == 'w') {
        if (playerY > 0) newY--;
        else { cout << "牆壁撞的我好疼阿" << endl; usleep(500000); return; }
    }
    else if (move == 's') {
        if (playerY < MAP_HEIGHT - 1) newY++;
        else { cout << "牆壁撞的我好疼阿" << endl; usleep(500000); return; }
    }
    else if (move == 'a') {
        if (playerX > 0) newX--;
        else { cout << "牆壁撞的我好疼阿" << endl; usleep(500000); return; }
    }
    else if (move == 'd') {
        if (playerX < MAP_WIDTH - 1) newX++;
        else { cout << "牆壁撞的我好疼阿" << endl; usleep(500000); return; }
    }
    else
    {
        cout << "在宮內請好好走路!" << endl;
        usleep(600000);
        return;
    }

    if (!checkCollisionWithObject(newX, newY)) {
        // 恢復舊位置的地圖內容
        map[playerY][playerX] = prevTile;

        // 移動玩家並記錄新的原始地圖內容
        playerX = newX;
        playerY = newY;
        prevTile = map[playerY][playerX];
    }
}
/*
* 將場景敘述獨立成一個自訂函式，內部以switch 函式管理每一回合的敘述。
* 參數:int run - 傳入回合數，讓switch 函式輸出相應場景
*/
void scene (int run)
{
	switch(run)
	{
		case 0:
            cout << "在這個充滿陰謀與權謀的古代宮廷中，你是一位想藉由進宮而達成夢想的新人。\n";
            cout << "每一位宮女、太監、甚至嬪妃，無論是身處高位還是低位，都在為權力而爾虞我詐。\n";
            cout << "在宮中，你需要運用智慧與勇氣，在宮廷中步步為營。\n";
            cout << "每一個選擇，無論是愛恨情仇，還是忠誠背叛，都將決定你在這個華麗但危險的宮廷中的命運。\n";
            cout << "請注意，在這個世界任何問題都將劇烈影響你的未來，再送出回答之前請仔細檢查是否有\n";
            cout << "1.多餘的符號(例如: ，。 .)\n";
            cout << "2.超過選項之數字(例如選項為1-4，卻回答6)\n";
            cout << "若不幸發生，可能會有意想不到且危險的後果在等待著你...\n";
            cout << "現在，請輸入1-4其中一個數字以進入遊戲\n";
			break;
        case 1:
            cout << " " << endl;
            cout << "在這座宏偉的宮殿中，有無數種途徑可以進入，選擇不同的方式將決定你在宮中的身份和命運。\n";
            cout << "1.宮女:低地位，需靠機會晉升，生存能力強\n";
            cout << "2.貴族小姐:初期即備受矚目，但易成為爭鬥目標\n";
            cout << "3.答應:直接參與後宮爭鬥，但缺乏背景\n";
            break;
        case 2:
            cout << " " << endl;
            cout << "對於初入宮廷的你，這是一個陌生且充滿挑戰的環境。對宮中的禮儀、規矩和權力結構完全陌生。\n";
            cout << "每個動作、言談舉止，都有可能影響你的未來。在做出每個決定之前，請仔細想想如何達成美滿的目標。\n";
            cout << "1.低調行事，避免捲入各黨鬥爭\n";
            cout << "2.積極巴結宮中權貴\n";
            cout << "3.依靠太監、宮女情報網\n";
            cout << "4.靠自身才藝吸引皇上\n";
            break;
		case 3:
            cout << " " << endl;
            cout << "與誰搞好關係？\n";
            cout << "在宮廷中，建立良好的關係對於生存和發展至關重要。\n";
            cout << "1.太監、宮女\n";
            cout << "2.權臣\n";
            cout << "3.嬪妃\n";
            cout << "4.皇帝\n";
            break;
		case 4:
            cout << " " << endl;
            cout << "一位嬪妃拉攏你站隊，這無疑是一個極具風險但也充滿潛力的機會。在這樣的情況下，你需要仔細考慮來決定是否加入她的陣營。\n";
            cout << "1.加入\n";
            cout << "2.拒絕\n";
            cout << "3.觀望\n";
            cout << "4.出賣她\n";
            break;
		case 5:
            cout << " " << endl;
            cout << "皇帝那天其實也在花園，但距離隔著太遠你並未發現，皇帝從遠處看到身穿一襲紫色紗裙的你，竟對你產生興趣來。\n";
            cout << "而你的態度將影響皇上對你的態度。\n";
            cout << "1.主動接近\n";
            cout << "2.拒絕，保持距離，做自己\n";
            cout << "3.若即若離\n";
            cout << "4.試圖謀求更高地位\n";
            break;
		case 6:
            cout << " " << endl;
            cout << "在彼此都心懷不軌、心思縝密的宮中，遭受到敵人的針對也是不可避免的。\n";
            cout << "有天你發現你好像在不知不覺中得罪了高貴妃，她最近一直在默默地針對你，想要把你除掉，你的處境岌岌可危，現在你該怎麼做?\n";
            cout << "1.忍耐\n";
            cout << "2.主動出擊\n";
            cout << "3.聯合其他嬪妃\n";
            cout << "4.討好皇后\n";
            break;
		case 7:
            cout << " " << endl;
            cout << "先前發生的危機已在時間的洗禮下趨近平靜，你真正認識到宮中的爾虞我詐，仍然心有餘悸。\n";
            cout << "這天皇帝不知為何召見你到他的殿內，一番理解後發覺皇上這是在跟你交易。\n";
            cout << "由於你近日與林貴人交情甚好，而林貴人懷孕也已4個半月，皇帝希望你在後宮中好好保護她，\n";
            cout << "若等到林貴人誕下龍子必有厚賞，但若發生意外則由她的侍衛與宮女及妳來承擔。\n";
            cout << "1.接受\n";
            cout << "2.拒絕\n";
            cout << "3.謀求更大利益\n";
            break;
		case 8:
            cout << " " << endl;
            cout << "皇帝近日身體欠佳，而在宮中只有你與宋貴妃生下皇子，其中宋貴妃的為太子，但皇帝早就認為其尚缺能力，\n";
            cout << "且年紀也尚小，打算重立太子，但宋貴妃的哥哥乃是朝廷重臣，皇帝顧忌她身後的勢力，他決定來問問你對此事的看法。\n";
            cout << "1.支持原太子\n";
            cout << "2.支持自己兒子\n";
            cout << "3.聯合當權宰相\n";
            cout << "4.靜觀其變\n";
            break;
		case 9:
            cout << " " << endl;
            cout << "面臨生死關頭，請問你是否願意放棄權力與財富?\n";
            cout << "情況十分危急，請盡快做出決定...\n";
            cout << "1.是，在宮廷內找生路\n";
            cout << "2.是，嘗試逃離\n";
            cout << "3.否，抗爭到底\n";
            break;
		default:
			cout << "來人，拖出去，斬了!";
			E=true;
	}
}
/*
* 將隨機事件的選項獨立成一個自訂函式，並依照選項輸出對應的描述並影響角色數值。
*
* 參數：
* - int n - 玩家選擇之選項，根據不同回答輸出對應的描述並影響角色數值。
*/
void option_incident (int n)
{
    if (n==5)
    {
        cout << "最後李貴人被證實這事不關她的事，皇上決定處罰那些傳謠者，皇上覺得你是個很有智慧的人!\n";
        emperor+=1;
        interaction +=1;
    }
    else if (n==6)
    {
        cout << "李貴人最後被證實這事根本與她無關，皇上決定重罰那些傳謠者!\n";
        emperor-=2;
        safety+=1;
    }
    else if (n==7)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(1,100);

        int chance;
        if (chance<=60)
        {
            cout << "你證明了李貴人根本與這件事無關!李貴人十分感謝你!皇上也稱讚你的冷靜與聰穎。\n";
            social+=1;
            emperor+=1;
            strategy+=1;
        }
        else
        {
            cout << "你的宮女沒有查出什麼，其他宮人甚至懷疑你與李貴人是一夥的...\n";
            safety-=1;
            interaction-=1;
        }
    }
    else
    {
        cout << "來人，拖出去，斬了!\n";
        E=true;
    }
}
/*
* 將隨機事件獨立成一個自訂函式。
* 註:隨機取數已在主函式內完成。
*/
void incident ()
{
    cout << " " << endl;
    cout << "皇宮內突發瘟疫，宮人接二連三感染，甚至有位嬪妃也命危。\n";
    cout << "流言謠傳是李貴人帶來的災難，指她與外界有所勾結，將病疫帶入宮中。\n";
    cout << "宮內一片恐慌，無人敢接近她。你會如何解決這件事?\n";
    cout << "5.謠言止於智者，不加入討論\n";
    cout << "6.跟著宮內的人們一起排擠她\n";
    cout << "7.決定還李貴人一個公道，派出自己的貼身宮女調查此事\n";
    int n;
    cin >> n;
    option_incident (n);
}
/*
 * 將所有的選項 1 獨立成一個函式，內部使用 switch 控制每回合的敘述。
 *
 * 參數：
 * - int run - 當前回合數，根據不同回合輸出對應的場景描述並影響角色數值。
 */
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
			cout << "但這會大幅影響你受寵的機會\n";
			strategy+=1;
			social-=1;
			safety+=1;
			break;
		case 3:
			cout << "不錯的選擇!太監和宮女通常有著深入的內部關係和情報來源。\n";
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
			if (social>=3&&ambition>=3&&strategy>=3)
			{
				cout << "你站在王宮金碧輝煌的大廳中，血液彷彿沸騰著在你的身體裡流動。你，終於成為了皇后。\n";
				cout << "這一刻的權力讓你感到興奮，更感到一種前所未有的自信，仿佛這世界的所有重擔都能輕易承擔，\n";
				cout << "所有的道路都可以掌握在手中，這一世終究活成了自己想要的模樣!\n";
				cout << "你的結局:皇后\n";
				E=true;
			}
			else if (social>=3&&ambition>=3&&strategy<3)
			{
				cout << "你所得到的，並非僅僅是皇帝的青睞，而是他對你所有心意的獨佔。\n";
				cout << "你知道，這份寵愛是如此的難得與珍貴，讓你感到無比的榮耀與驕傲。\n";
				cout << "你站在他的面前，眼中只有他一個人，所有的期待與渴望都聚焦在他的眼神中。\n";
				cout << "那一刻，你無法抗拒心中那股強烈的情感，它讓你既感動又激動，這個世界都在為你鋪陳一條金光閃閃的道路。\n";
				cout << "你的結局:寵妃\n";
				E=true;
			}
			else
			{
			 	cout << "你在宮中似乎並不積極爭奪高位，偶爾獲得些許恩寵，卻從不奢望太多。\n";
                cout << "當宮廷爾虞我詐的鬥爭愈演愈烈，戰亂到來，所有的權謀與爭鬥都化為過眼雲煙。\n";
                cout << "最終，你在深宮角落裡默默度過平凡一生的人，無人記起。\n";
                cout << "你的結局:平平無奇";
			 	E=true;
			}
			break;
		case 9:
			cout << "先前在宮中的決策失誤連連，已使你聲名狼藉，如今戰亂突發，你不得不在皇宮尋求庇護。\n";
			cout << "可他人冷眼旁觀，最終你被貶為卑賤的低奴，任人驅使。昔日的雄心壯志化為泡沫，餘生只剩無望的囚困。\n";
			cout << "你的結局:奴婢";
			E=true;
			break;
		default:
			cout << "來人，拖出去，斬了!";
			E=true;
	}
}
/*
 * 將所有的選項 2 獨立成一個函式，內部使用 switch 控制每回合的敘述。
 *
 * 參數：
 * - int run - 當前回合數，根據不同回合輸出對應的場景描述並影響角色數值。
 *
*  特殊機制：
 * - 某些回合（如 8）會根據隨機機率決定不同結果。
 */
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
            cout << "找對高位者，你的得勢會極快!在這當中可能會大量樹敵\n";
			ambition+=1;
			interaction+=1;
			social+=1;
			safety-=2;
			break;
		case 3:
			cout << "權臣為你提供更多的機會，並且讓你在權力鬥爭中站穩腳步。這些人物的支持往往能為你帶來穩固的後盾。\n";
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
		    cout << "看起來你對爭寵沒什麼興趣呢!保持距離使你大程度上的維持你的生命安全，\n";
			cout << "但皇上對你遠離他的態度感到不滿，請想想如何重新擄獲他的心吧!\n";
			ambition-=1;
			emperor-=2;
			safety+=2;
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
            if (chance <= 33){
                cout << "你站在王宮金碧輝煌的大廳中，血液彷彿沸騰著在你的身體裡流動。你，終於成為了皇后。\n";
                cout << "這一刻的權力讓你感到興奮，更感到一種前所未有的自信，仿佛這世界的所有重擔都能輕易承擔，\n";
                cout << "所有的道路都可以掌握在手中，這一世終究活成了自己想要的模樣!\n";
                cout << "你的結局:皇后\n";
                E=true;
			}
			else
			{
                cout << "你遭到宋貴妃家裡勢力的威脅，你的處境岌岌可危...\n";
            }
            break;
        }
		case 9:
			if (safety>=3)
			{
				cout << "離宮後的日子雖稱不上富足，卻讓你重獲自由與平靜。\n";
				cout << "昔日嬪妃的尊榮已成過往，如今的你隱居鄉野，無需再在深宮中步步為營。\n";
				cout << "你才發現，這份平凡與寧靜，竟是你從未奢望過的幸福。\n";
				cout << "你的結局:離宮，過著平靜的生活\n";
				E=true;
			}
			else
			{
				cout << "你步步為營，從答應晉封到更高的稱號，卻因一場宮變失勢。\n";
                cout << "夜色深沉，侍女奉上一碗毒湯，你輕輕一嘆，原來，深宮之中，終究無人能善終。\n";
                cout << "你的結局:宮鬥失敗死亡\n";
				E=true;
			}
			break;
		default:
			cout << "來人，拖出去，斬了!";
			E=true;
	}
}
/*
 * 將所有的選項 3 獨立成一個函式，內部使用 switch 控制每回合的敘述。
 *
 * 參數：
 * - int run - 當前回合數，根據不同回合輸出對應的場景描述並影響角色數值。
 *
 *  特殊機制：
 * - 某些回合（如 7, 9）會根據隨機機率決定不同結果。
 */
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
            cout << "消息靈通，遇到事情時能預先做打算，以防遭人陷害\n";
            cout << "但地位難以提升，被揭發時無人能當靠山\n";
			strategy+=1;
			social+=1;
			break;
		case 3:
            cout << "嬪妃們的權力與影響力不亞於君王。與她們建立良好關係，對於保護自己的安全、爭取機會都至關重要\n";
			social+=1;
			strategy+=1;
			break;
		case 4:
            cout << "選擇觀望使你大幅減少加入陣營後可能會遇到的權力鬥爭\n";
			safety+=2;
			break;
		case 5:
            cout << "若即若離的態度激起了皇上的征服慾，這也證明了你的策略十分奏效!\n";
			emperor+=1;
			strategy+=1;
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
            if (chance <= 40)
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
                cout << "皇帝認為你無理取鬧，你遭到後宮嬪妃們的譏笑，高貴妃心想，現在是最佳的時機，\n";
                cout << "是時候除掉你了，快想想怎麼拯救自己吧!\n";
                social-=1;
                interaction-=2;
                safety-=1;
            }
			break;
		}
		case 8:
    		if (interaction>=3)
			{
				cout << "你站在王宮金碧輝煌的大廳中，血液彷彿沸騰著在你的身體裡流動。你，終於成為了皇后。\n";
				cout << "這一刻的權力讓你感到興奮，更感到一種前所未有的自信，仿佛這世界的所有重擔都能輕易承擔，\n";
				cout << "所有的道路都可以掌握在手中，這一世終究活成了自己想要的模樣!\n";
				cout << "你的結局:皇后\n";
				E=true;
			}
			else
			{
		 		cout << "戰亂爆發，你曾試圖尋求庇護，卻無人願意相助。最終，你被打入冷宮，終日困於破敗宮牆內。\n";
		 		cout << "昔日嬪妃的尊榮早已成空，直至死去，也無人問津。\n";
		 		cout << "你的結局:被打入冷宮";
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
					cout << "你所得到的，並非僅僅是皇帝的青睞，而是他對你所有心意的獨佔。\n";
                    cout << "你知道，這份寵愛是如此的難得與珍貴，讓你感到無比的榮耀與驕傲。\n";
                    cout << "你站在他的面前，眼中只有他一個人，所有的期待與渴望都聚焦在他的眼神中。\n";
                    cout << "那一刻，你無法抗拒心中那股強烈的情感，它讓你既感動又激動，這個世界都在為你鋪陳一條金光閃閃的道路。\n";
                    cout << "你的結局:寵妃\n";
					E=true;
				}
				else
				{
			 		cout << "戰亂爆發，你曾試圖尋求庇護，卻無人願意相助。最終，你被打入冷宮，終日困於破敗宮牆內。\n";
                    cout << "昔日嬪妃的尊榮早已成空，直至死去，也無人問津。\n";
                    cout << "你的結局:被打入冷宮";
			 		E=true;
				}
			}
			else
			{
                cout << "你步步為營，從答應晉封到更高的稱號，卻因一場宮變失勢。\n";
                cout << "夜色深沉，侍女奉上一碗毒湯，你輕輕一嘆，原來，深宮之中，終究無人能善終。\n";
                cout << "你的結局:宮鬥失敗死亡";
				E=true;
			}
			break;
		}
		default:
			cout << "來人，拖出去，斬了!";
			E=true;
	}
}
/*
 * 將所有的選項 4 獨立成一個函式，內部使用 switch 控制每回合的敘述。
 *
 * 參數：
 * - int run - 當前回合數，根據不同回合輸出對應的場景描述並影響角色數值。
 *
 *  特殊機制：
 * - 某些回合（如 4, 5, 6, 8）會根據隨機機率決定不同結果。
 */
void option_D (int run)
{
	 switch(run)
	{
		case 0:
			break;
		case 2:
            cout << "和他搞好關係直接影響到你的地位和未來發展。有提升成為寵妃的機率及升位快速\n";
            cout << "但得寵有風險，且競爭激烈\n";
			emperor+=1;
			safety-=1;
			break;
		case 3:
			cout << "他宮中最大的權力者，將會直接影響你未來的地位及處境\n";
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
				if (chance<=40)
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
				cout << "「本宮與你素不相識，何須摻和此事？」她不願與你為敵，但更不願為了你而招惹風波。";
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
				if (strategy>=3)
				{
				 	cout << "你站在王宮金碧輝煌的大廳中，血液彷彿沸騰著在你的身體裡流動。你，終於成為了皇后。\n";
                    cout << "這一刻的權力讓你感到興奮，更感到一種前所未有的自信，仿佛這世界的所有重擔都能輕易承擔，\n";
                    cout << "所有的道路都可以掌握在手中，這一世終究活成了自己想要的模樣!\n";
                    cout << "你的結局:皇后\n";
				 	E=true;
				}
				else
				{
				 	cout << "你所得到的，並非僅僅是皇帝的青睞，而是他對你所有心意的獨佔。\n";
                    cout << "你知道，這份寵愛是如此的難得與珍貴，讓你感到無比的榮耀與驕傲。\n";
                    cout << "你站在他的面前，眼中只有他一個人，所有的期待與渴望都聚焦在他的眼神中。\n";
                    cout << "那一刻，你無法抗拒心中那股強烈的情感，它讓你既感動又激動，這個世界都在為你鋪陳一條金光閃閃的道路。\n";
                    cout << "你的結局:寵妃\n";
				 	E=true;
				}
			}
			else
			{
				cout << "你在宮中似乎並不積極爭奪高位，偶爾獲得些許恩寵，卻從不奢望太多。\n";
                cout << "當宮廷爾虞我詐的鬥爭愈演愈烈，戰亂到來，所有的權謀與爭鬥都化為過眼雲煙。\n";
                cout << "最終，你在深宮角落裡默默度過平凡一生的人，無人記起。\n";
                cout << "你的結局:平平無奇";
				E=true;
			}
			break;
	    }
		default:
			cout << "來人，拖出去，斬了!";
			E=true;
	}
}
/*
 * 主函式：使用 while 迴圈支援整個遊戲的流程，並使用布林值判斷是否繼續進行遊戲。
 *
 * 主要流程：
 * 1. 在每回合開始時，根據當前回合數 `run` 觸發不同場景和事件。
 * 2. 第五回合（`run == 5`）會進行地圖體驗，並依照布林值 `F` 判斷是否已達終點。若到達終點，`return true` 並將 `F` 設為 `false`，跳出地圖生成迴圈，繼續主劇情。
 * 3. 第六回合結束，有機會觸發隨機事件，使用 C++ 標準庫中的 `random_device` 和 `mt19937` 來產生隨機數。隨機事件的觸發機率設定為45%，當隨機事件被觸發時，會調用 `incident()` 函數來處理事件邏輯。
 * 4. 當主劇情結束後，依照布林值 `E` 判斷是否結束遊戲，若遊戲結束，`return true` 並結束程式執行。
 *
 * 輸入：
 * - `n`（整數）：玩家選擇的選項，根據不同選項執行相應的操作。
 * - `move`（字符）：用來處理玩家的地圖移動。
 *
 * 遊戲結束條件：
 * - 當 `E == true` 時，遊戲結束。
 */
int main() {
    int n, run = 0;
    char move;

	while (E==false)
	{
        	usleep(1000000);
        	if (run==5)
        	{
                while (true)
                {
                    if (F==true) break;
                    showMap();
                    cin >> move;
                    handleMovement(move);
                }
        	}

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

        	usleep(1000000);
        	if (run==6)
        	{
        	    random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int> dist(1,100);

                int chance = dist(gen);
                if (chance<=45)
                {
                    incident();
                }
        	}

        	run++;
    	}

    return 0;
}
