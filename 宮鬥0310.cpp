#include <iostream>
#include <random>  // ��{�N���H���Ʋ��ͤ覡
#include <cstdlib>  // system("clear") �� system("cls")
#include <unistd.h>  // �Ω� usleep�]Linux/macOS �U�^�Ϊ� Windows �� Sleep()
#include <cctype>  // �Ω� tolower ���
using namespace std;
int social=0,ambition=0,strategy=0,emperor=0,interaction=0,safety=0; //�N��O�ȳ]�w�b�����ܼơA�H�Ѧۭq�禡�ϥΡA�o�ǼƭȱN�v�T�C������
bool E=false,F=false; //��������P�w��
const int MAP_WIDTH = 10;
const int MAP_HEIGHT = 10;
int playerX = 1, playerY = 0;  // ���a��l��m
char prevTile = '#';  // �O�����a�W�@�Ӧ�m���a�Ϥ����A�H�K��_�a��
// �C���a�ϡA�ϥΤ��P�Ÿ��N���P�a��
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
// ��ܦa�ϡA�ϥ� system("clear") �� system("cls") �ӲM���e��
void showMap() {
    #ifdef _WIN32
        system("cls");  // Windows �M��
    #else
        system("clear"); // Linux/macOS �M��
    #endif

    cout << "�o�ѡA�]�\�O���F�Y���餤�������A�S�άO���F�ƸѤߤ����{�e�A�A�Ө�F�s���C\n";
    cout << "�A�b�s���y���a���B\n";
    cout << "*�ЧQ����L�WW/w�BS/s�BA/a�BD/d�i��W�U���k���ʡA�q�c��������s���\n";

    // ��ܦa�Ϥ������Хܤ�r
    cout << "=== �a�Ϥ������� ===" << endl;
    cout << "#  - �D�� (Road)" << endl;
    cout << "\033[38;5;8mS  - ���Y (Stone)\033[0m" << endl; // ���Y���Ǧ�
    cout << "\033[38;5;13mC  - ��� (Cherry)\033[0m" << endl; // ��ᬰ����
    cout << "\033[38;5;2mT  - �� (Grass)\033[0m" << endl;   // �󬰺��
    cout << "\033[38;5;11mH  - �s��� (Herb Garden)\033[0m" << endl; // �s��鬰����
    cout << "\033[38;5;9mP  - ���a (Player)\033[0m" << endl; // ���a������
    cout << "=====================" << endl;

    // ��ܦa��
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            if (x == playerX && y == playerY) {
                // �]�m���a�C�⬰����
                cout << "\033[38;5;9m" << "P  " << "\033[0m";  // ������ܪ��a
            } else {
                // �ھڦa�Ϥ��e��ܤ��P���r��
                if (map[y][x] == 'S') {
                    cout << "\033[38;5;8m" << "S  " << "\033[0m";  // ���Y��ܦǦ�
                } else if (map[y][x] == 'C') {
                    cout << "\033[38;5;13m" << "C  " << "\033[0m";  // �����ܯ���
                } else if (map[y][x] == 'T') {
                    cout << "\033[38;5;2m" << "T  " << "\033[0m";  // ����ܺ��
                } else if (map[y][x] == 'H') {
                    cout << "\033[38;5;11m" << "H  " << "\033[0m";  // �s�����ܶ���
                } else if (map[y][x] == '#') {
                    cout << "\033[38;5;7m" << "#  " << "\033[0m";  // �D����ܦǦ�
                }
            }
        }
        cout << endl;
    }
}
/*
* �H�_���j��P�_�a�I�A�ÿ�X������r�C
* �Ѽ�:
* int newX - �a�� x �y��
* int newY - �a�� y �y��
*/
bool checkCollisionWithObject(int newX, int newY) {
    if (map[newY][newX] == 'S') {
        cout << "�o���Y�]�ӵw�F" << endl;
        usleep(500000); // �Ȱ� 0.5 ��H��ܰT��
        return true;
    } else if (map[newY][newX] == 'C') {
        cout << "�o���ש�}�F�A�o�i�u����" << endl;
        usleep(500000);
        return true;
    } else if (map[newY][newX] == 'T') {
        cout << "�o��h�[�S���աA�����ڪ��}��F�A���|��s�p���l�ӳB�z" << endl;
        usleep(500000);
        return true;
    } else if (map[newY][newX] == 'H') {
        cout << "�ש��s���F!" << endl;
        usleep(2000000);
        F=true;
        return false;
    }
    return false;
}
/*
* �H�_���j��P�_�P�O���ϥΪ̤W/�U/��/�k�A�æ��a����ɧP�_�A�Y����|��X���ܤ�r�ð��d�b��a�C
* �Ѽ�:char move - �ϥΪ̿�ܪ����ʤ�V
*/
void handleMovement(char move) {
    int newX = playerX, newY = playerY;

    move = tolower(move);  // �N��J�r���ର�p�g

    if (move == 'w') {
        if (playerY > 0) newY--;
        else { cout << "��������ڦn�k��" << endl; usleep(500000); return; }
    }
    else if (move == 's') {
        if (playerY < MAP_HEIGHT - 1) newY++;
        else { cout << "��������ڦn�k��" << endl; usleep(500000); return; }
    }
    else if (move == 'a') {
        if (playerX > 0) newX--;
        else { cout << "��������ڦn�k��" << endl; usleep(500000); return; }
    }
    else if (move == 'd') {
        if (playerX < MAP_WIDTH - 1) newX++;
        else { cout << "��������ڦn�k��" << endl; usleep(500000); return; }
    }
    else
    {
        cout << "�b�c���Цn�n����!" << endl;
        usleep(600000);
        return;
    }

    if (!checkCollisionWithObject(newX, newY)) {
        // ��_�¦�m���a�Ϥ��e
        map[playerY][playerX] = prevTile;

        // ���ʪ��a�ðO���s����l�a�Ϥ��e
        playerX = newX;
        playerY = newY;
        prevTile = map[playerY][playerX];
    }
}
/*
* �N�����ԭz�W�ߦ��@�Ӧۭq�禡�A�����Hswitch �禡�޲z�C�@�^�X���ԭz�C
* �Ѽ�:int run - �ǤJ�^�X�ơA��switch �禡��X��������
*/
void scene (int run)
{
	switch(run)
	{
		case 0:
            cout << "�b�o�ӥR�����ѻP�v�Ѫ��j�N�c�ʤ��A�A�O�@��Q�ǥѶi�c�ӹF���ڷQ���s�H�C\n";
            cout << "�C�@��c�k�B�ӺʡB�Ʀ����m�A�L�׬O���B�����٬O�C��A���b���v�O�Ӻ����ڶB�C\n";
            cout << "�b�c���A�A�ݭn�B�δ��z�P�i��A�b�c�ʤ��B�B����C\n";
            cout << "�C�@�ӿ�ܡA�L�׬O�R�뱡���A�٬O���ۭI�q�A���N�M�w�A�b�o�ӵ��R���M�I���c�ʤ����R�B�C\n";
            cout << "�Ъ`�N�A�b�o�ӥ@�ɥ�����D���N�@�P�v�T�A�����ӡA�A�e�X�^�����e�ХJ���ˬd�O�_��\n";
            cout << "1.�h�l���Ÿ�(�Ҧp: �A�C .)\n";
            cout << "2.�W�L�ﶵ���Ʀr(�Ҧp�ﶵ��1-4�A�o�^��6)\n";
            cout << "�Y�����o�͡A�i��|���N�Q����B�M�I����G�b���ݵۧA...\n";
            cout << "�{�b�A�п�J1-4�䤤�@�ӼƦr�H�i�J�C��\n";
			break;
        case 1:
            cout << " " << endl;
            cout << "�b�o�y�������c�����A���L�ƺس~�|�i�H�i�J�A��ܤ��P���覡�N�M�w�A�b�c���������M�R�B�C\n";
            cout << "1.�c�k:�C�a��A�ݾa���|�ʤɡA�ͦs��O�j\n";
            cout << "2.�Q�ڤp�j:����Y�ƨ��f�ءA�������������ؼ�\n";
            cout << "3.����:�����ѻP��c�����A���ʥF�I��\n";
            break;
        case 2:
            cout << " " << endl;
            cout << "����J�c�ʪ��A�A�o�O�@�ӭ��ͥB�R���D�Ԫ����ҡC��c����§���B�W�x�M�v�O���c�������͡C\n";
            cout << "�C�Ӱʧ@�B�����|��A�����i��v�T�A�����ӡC�b���X�C�ӨM�w���e�A�ХJ�ӷQ�Q�p��F���������ؼСC\n";
            cout << "1.�C�զ�ơA�קK���J�U�Ұ���\n";
            cout << "2.�n���ڵ��c���v�Q\n";
            cout << "3.�̾a�ӺʡB�c�k������\n";
            cout << "4.�a�ۨ��~���l�ެӤW\n";
            break;
		case 3:
            cout << " " << endl;
            cout << "�P�ַd�n���Y�H\n";
            cout << "�b�c�ʤ��A�إߨ}�n�����Y���ͦs�M�o�i�������n�C\n";
            cout << "1.�ӺʡB�c�k\n";
            cout << "2.�v��\n";
            cout << "3.���m\n";
            cout << "4.�ӫ�\n";
            break;
		case 4:
            cout << " " << endl;
            cout << "�@�����m���l�A�����A�o�L�ìO�@�ӷ��㭷�I���]�R����O�����|�C�b�o�˪����p�U�A�A�ݭn�J�ӦҼ{�ӨM�w�O�_�[�J�o���}��C\n";
            cout << "1.�[�J\n";
            cout << "2.�ڵ�\n";
            cout << "3.�[��\n";
            cout << "4.�X��o\n";
            break;
		case 5:
            cout << " " << endl;
            cout << "�ӫҨ��Ѩ��]�b���A���Z���j�ۤӻ��A�å��o�{�A�ӫұq���B�ݨ쨭��@ŧ���⯽�Ȫ��A�A����A���Ϳ���ӡC\n";
            cout << "�ӧA���A�ױN�v�T�ӤW��A���A�סC\n";
            cout << "1.�D�ʱ���\n";
            cout << "2.�ڵ��A�O���Z���A���ۤv\n";
            cout << "3.�Y�Y�Y��\n";
            cout << "4.�չϿѨD�󰪦a��\n";
            break;
		case 6:
            cout << " " << endl;
            cout << "�b���������h���y�B�߫俦�K���c���A�D����ĤH���w��]�O���i�קK���C\n";
            cout << "���ѧA�o�{�A�n���b������ı���o�o�F���Q�m�A�o�̪�@���b�q�q�a�w��A�A�Q�n��A�����A�A���B�ҧħĥi�M�A�{�b�A�ӫ��?\n";
            cout << "1.�ԭ@\n";
            cout << "2.�D�ʥX��\n";
            cout << "3.�p�X��L���m\n";
            cout << "4.�Q�n�ӦZ\n";
            break;
		case 7:
            cout << " " << endl;
            cout << "���e�o�ͪ��M���w�b�ɶ����~§�U�ͪ��R�A�A�u���{�Ѩ�c���������ڶB�A���M�ߦ��l���C\n";
            cout << "�o�ѬӫҤ�������l���A��L�������A�@�f�z�ѫ�oı�ӤW�o�O�b��A����C\n";
            cout << "�ѩ�A���P�L�Q�H�污�Ʀn�A�ӪL�Q�H�h���]�w4�ӥb��A�ӫҧƱ�A�b��c���n�n�O�@�o�A\n";
            cout << "�Y����L�Q�H�ϤU�s�l�����p��A���Y�o�ͷN�~�h�Ѧo���ͽûP�c�k�Ωp�өӾ�C\n";
            cout << "1.����\n";
            cout << "2.�ڵ�\n";
            cout << "3.�ѨD��j�Q�q\n";
            break;
		case 8:
            cout << " " << endl;
            cout << "�ӫҪ�騭���ΡA�Ӧb�c���u���A�P���Q�m�ͤU�Ӥl�A�䤤���Q�m�����Ӥl�A���ӫҦ��N�{����|�ʯ�O�A\n";
            cout << "�B�~���]�|�p�A���⭫�ߤӤl�A�����Q�m�������D�O�§ʭ��ڡA�ӫ��U�Ҧo���᪺�դO�A�L�M�w�ӰݰݧA�惡�ƪ��ݪk�C\n";
            cout << "1.�����Ӥl\n";
            cout << "2.����ۤv��l\n";
            cout << "3.�p�X���v�_��\n";
            cout << "4.�R�[����\n";
            break;
		case 9:
            cout << " " << endl;
            cout << "���{�ͦ����Y�A�аݧA�O�_�@�N����v�O�P�]�I?\n";
            cout << "���p�Q���M��A�кɧְ��X�M�w...\n";
            cout << "1.�O�A�b�c�ʤ���͸�\n";
            cout << "2.�O�A���հk��\n";
            cout << "3.�_�A�ܪ��쩳\n";
            break;
		default:
			cout << "�ӤH�A��X�h�A�٤F!";
			E=true;
	}
}
void option_incident (int n)
{
    if (n==5)
    {
        cout << "�̫���Q�H�Q�ҹ�o�Ƥ����o���ơA�ӤW�M�w�B�@���Ƕ����̡A�ӤWı�o�A�O�ӫܦ����z���H!\n";
        emperor+=1;
        interaction +=1;
    }
    else if (n==6)
    {
        cout << "���Q�H�̫�Q�ҹ�o�Ʈڥ��P�o�L���A�ӤW�M�w���@���Ƕ�����!\n";
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
            cout << "�A�ҩ��F���Q�H�ڥ��P�o��ƵL��!���Q�H�Q���P�§A!�ӤW�]���g�A���N�R�P�o�o�C\n";
            social+=1;
            emperor+=1;
            strategy+=1;
        }
        else
        {
            cout << "�A���c�k�S���d�X����A��L�c�H�Ʀ��h�çA�P���Q�H�O�@�٪�...\n";
            safety-=1;
            interaction-=1;
        }
    }
    else
    {
        cout << "�ӤH�A��X�h�A�٤F!\n";
        E=true;
    }
}
/*
* �N�H���ƥ�W�ߦ��@�Ӧۭq�禡�A�������Hif ����P�_�O�_�ŦX�d��^�X���A�A�ϥ�random �H�����ơA���H���ƥ�O�_�|�o��
* �Ѽ�:int run - �ǤJ�^�X�ơA��if ����P�_�O�_�ŦX�d��^�X��
*/
void incident (int run)
{
    if (run==6||run==7)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(1,100);

        int chance = dist(gen);
        if (chance<=40)
        {
            cout << "�Ӯc����o�E�̡A�c�H���G�s�T�P�V�A�Ʀܦ������m�]�R�M�C\n";
            cout << "�y�����ǬO���Q�H�a�Ӫ��a���A���o�P�~�ɦ��Ҥĵ��A�N�f�̱a�J�c���C\n";
            cout << "�c���@�����W�A�L�H������o�C�A�|�p��ѨM�o���?\n";
            cout << "5.������󴼪̡A���[�J�Q��\n";
            cout << "6.��ۮc�����H�̤@�_�����o\n";
            cout << "7.�M�w�٧��Q�H�@�Ӥ��D�A���X�ۤv���K���c�k�լd����\n";
            int n;
            cin >> n;
        }
    }
}
/*
 * �N�Ҧ����ﶵ 1 �W�ߦ��@�Ө禡�A�����ϥ� switch ����C�^�X���ԭz�C
 *
 * �ѼơG
 * - int run - ��e�^�X�ơA�ھڤ��P�^�X��X�����������y�z�üv�T����ƭȡC
 */
void option_A (int run)
{
	 switch(run)
	{
		case 0:
			break;
		case 1:
            cout << "�A�O�X�ͩ�G�{���������k�A�Q��J�c�A��\n";
            strategy+=1;
            break;
		case 2:
			cout << "���o�|�j�T�v�T�A���d�����|\n";
			strategy+=1;
			social-=1;
			safety+=1;
			break;
		case 3:
			cout << "���������!�ӺʩM�c�k�q�`���۲`�J���������Y�M�����ӷ��C\n";
			strategy+=1;
			social+=1;
			safety-=1;
			break;
		case 4:
		    cout << "�A�P��c���m�����Y���K�F�A�o�]�W�[�A�������O�A���ѩ�[�J�}��y�����j�����I�A�A���I���Ӧw��...\n";
			interaction+=1;
			social+=1;
			safety-=1;
			break;
		case 5:
            cout << "�ӫҹ�A���D�ʷP��n�_�A�A�w�e�ڥL�߸̪��@�u���a!���p�ߨ�L�c�ʶդO�P�ҧ��̹�A���ͼķN�A�L�̥��b���A���¯١C\n";
			emperor+=2;
			ambition+=1;
			safety-=1;
			break;
		case 6:
            cout << "�]�\�O�Ӧn�M�w�O?�A�קK�F�P�ĤH�������Ĭ�A�o�����M�w�]�ϧA�ȮɫO�@�F�ۨ��w���C\n";
            cout << "���o�רs�L�k�ѨM���D�A�A�Q�����n�z���H�A��Q�P�A���������m��A�O���[��C\n";
			social-=1;
			ambition-=1;
			strategy+=1;
			safety+=1;
			break;
		case 7:
            cout << "�A���U�o�x�������ȡA�ڨتA�A���i��A���A�]�ӽİʤF!�L�Q�H�̫�b�A�����U�U���\�ϤU�s�l�A�ӤW�s�ߤj��!\n";
            cout << "�z!�A�{�b�i�O�ӤW��������l���A����@��H���ҧ��]�O�ܦX�z��...\n";
			emperor+=2;
			ambition+=2;
			strategy-=1;
			safety-=2;
			break;
		case 8:
			if (social>=3&&ambition>=3&&strategy>=3)
			{
				cout << "�A���b���c���ѽ��ת��j�U���A��G�ϩ��m�˵ۦb�A������̬y�ʡC�A�A�ש󦨬��F�ӦZ�C\n";
				cout << "�o�@�誺�v�O���A�P�쿳�ġA��P��@�ثe�ҥ������۫H�A���o�@�ɪ��Ҧ����᳣�໴���Ӿ�A\n";
				cout << "�Ҧ����D�����i�H�x���b�⤤�A�o�@�@�רs�����F�ۤv�Q�n���Ҽ�!\n";
				cout << "�A������:�ӦZ\n";
				E=true;
			}
			else if (social>=3&&ambition>=3&&strategy<3)
			{
				cout << "�A�ұo�쪺�A�ëD�ȶȬO�ӫҪ��C���A�ӬO�L��A�Ҧ��߷N���W���C\n";
				cout << "�A���D�A�o���d�R�O�p�������o�P�öQ�A���A�P��L�񪺺aģ�Pź�ơC\n";
				cout << "�A���b�L�����e�A�����u���L�@�ӤH�A�Ҧ������ݻP���泣�E�J�b�L���������C\n";
				cout << "���@��A�A�L�k�ܩڤߤ����ѱj�P�����P�A�����A�J�P�ʤS�E�ʡA�o�ӥ@�ɳ��b���A�Q���@�������{�{���D���C\n";
				cout << "�A������:�d�m\n";
				E=true;
			}
			else
			{
			 	cout << "�A�b�c�����G�ä��n�����ܰ���A������o�ǳ\���d�A�o�q������Ӧh�C\n";
                cout << "��c�ʺ����ڶB�������U�t�U�P�A�Զè�ӡA�Ҧ����v�ѻP�������Ƭ��L�����ϡC\n";
                cout << "�̲סA�A�b�`�c�������q�q�׹L���Z�@�ͪ��H�A�L�H�O�_�C\n";
                cout << "�A������:�����L�_";
			 	E=true;
			}
			break;
		case 9:
			cout << "���e�b�c�����M�����~�s�s�A�w�ϧA�n�W�T�ǡA�p���Զì�o�A�A���o���b�Ӯc�M�D���@�C\n";
			cout << "�i�L�H�N�����[�A�̲קA�Q�S�����⪺�C���A���H�X�ϡC���骺���ߧ��ӤƬ��w�j�A�l�ͥu�ѵL�檺�}�x�C\n";
			cout << "�A������:���A";
			E=true;
			break;
		default:
			cout << "�ӤH�A��X�h�A�٤F!";
			E=true;
	}
}
/*
 * �N�Ҧ����ﶵ 2 �W�ߦ��@�Ө禡�A�����ϥ� switch ����C�^�X���ԭz�C
 *
 * �ѼơG
 * - int run - ��e�^�X�ơA�ھڤ��P�^�X��X�����������y�z�üv�T����ƭȡC
 *
*  �S�����G
 * - �Y�Ǧ^�X�]�p 8�^�|�ھ��H�����v�M�w���P���G�C
 */
void option_B (int run)
{
	 switch(run)
	{
		case 0:
			break;
		case 1:
            cout << "�A�O��ʬ����ӿ˰걭���k�A�a�ڭI���㻮\n";
            social+=1;
            break;
		case 2:
            cout << "��ﰪ��̡A�A���o�շ|����!�b�o���i��|�j�q���\n";
			ambition+=1;
			interaction+=1;
			social+=1;
			safety-=2;
			break;
		case 3:
			cout << "�v�ڬ��A���ѧ�h�����|�A�åB���A�b�v�O��������í�}�B�C�o�ǤH������������ର�A�a��í�T����ޡC\n";
			ambition+=1;
			interaction+=1;
			safety-=1;
			break;
		case 4:
		    cout << "�A�ڵ��F���m���ܽСA�o�ϱo�A�P���m�̪����Y�c�ơA���]���S���[�J�}��A���C�F���I�A�ϱo�A�����w���C\n";
		    cout << "�ӬӫҤ]�Y��A���M���A�W�[��A���n�P!\n";
			interaction-=1;
			social-=1;
			safety+=1;
			emperor+=1;
			break;
		case 5:
		    cout << "�ݰ_�ӧA�盛�d�S���򿳽�O!�O���Z���ϧA�j�{�פW�������A���ͩR�w���A\n";
			cout << "���ӤW��A�����L���A�׷P�줣���A�зQ�Q�p�󭫷s����L���ߧa!\n";
			ambition-=1;
			emperor-=2;
			safety+=2;
			break;
		case 6:
		    cout << "�i�𪺦���!�A�ֳt�������A������AĹ�o�@�ǤH������A���]�o�o�F���Q�m�}�窺���m�̡C\n";
		    cout << "�ݥL�̪��ʧ@�W�W�A�����S�O�n�����֡A��M�A�]���ҥ~�C\n";
			social+=1;
			ambition+=1;
			interaction-=1;
			safety-=1;
			break;
		case 7:
		    cout << "�ӫҳQ�A�ڵ��P�줣���A�M�w�Ǧ��d�z�A���a��A�A���쬰�`�b�C���M�ڤ��O�ƾǮa�A���oť�_�Ӥ��ӧ���a?\n";
		    cout << "�O��ߡA��Υ����j���D�֡A�A�ϦӤ��A�����L�H���ҧ��A����ۦb���ͬ�!\n";
			emperor-=1;
			ambition-=2;
			strategy+=1;
			safety+=1;
			break;
		case 8:
		{
			random_device rd;  // �u�����H���ƺؤl
            mt19937 gen(rd()); // �����H���Ƥ���
            uniform_int_distribution<int> dist(1, 100);  // ���� 1~100 �������Ʀr

            int chance = dist(gen);  // ����H����
            if (chance <= 33){
                cout << "�A���b���c���ѽ��ת��j�U���A��G�ϩ��m�˵ۦb�A������̬y�ʡC�A�A�ש󦨬��F�ӦZ�C\n";
                cout << "�o�@�誺�v�O���A�P�쿳�ġA��P��@�ثe�ҥ������۫H�A���o�@�ɪ��Ҧ����᳣�໴���Ӿ�A\n";
                cout << "�Ҧ����D�����i�H�x���b�⤤�A�o�@�@�רs�����F�ۤv�Q�n���Ҽ�!\n";
                cout << "�A������:�ӦZ\n";
                E=true;
			}
			else
			{
                cout << "�A�D�짺�Q�m�a�̶դO���¯١A�A���B�ҧħĥi�M...\n";
            }
            break;
        }
		case 9:
			if (safety>=3)
			{
				cout << "���c�᪺��l���٤��W�I���A�o���A����ۥѻP���R�C\n";
				cout << "�������m���L�a�w���L���A�p�����A���~�m���A�L�ݦA�b�`�c���B�B����C\n";
				cout << "�A�~�o�{�A�o�����Z�P���R�A���O�A�q������L�����֡C\n";
				cout << "�A������:���c�A�L�ۥ��R���ͬ�\n";
				E=true;
			}
			else
			{
				cout << "�A�B�B����A�q�����ʫʨ�󰪪��ٸ��A�o�]�@���c�ܥ��աC\n";
                cout << "�]��`�I�A�ͤk�^�W�@�J�r���A�A�����@�ġA��ӡA�`�c�����A�רs�L�H�ൽ�סC\n";
                cout << "�A������:�c�����Ѧ��`\n";
				E=true;
			}
			break;
		default:
			cout << "�ӤH�A��X�h�A�٤F!";
			E=true;
	}
}
/*
 * �N�Ҧ����ﶵ 3 �W�ߦ��@�Ө禡�A�����ϥ� switch ����C�^�X���ԭz�C
 *
 * �ѼơG
 * - int run - ��e�^�X�ơA�ھڤ��P�^�X��X�����������y�z�üv�T����ƭȡC
 *
 *  �S�����G
 * - �Y�Ǧ^�X�]�p 7, 9�^�|�ھ��H�����v�M�w���P���G�C
 */
void option_C (int run)
{
	 switch(run)
	{
		case 0:
			break;
		case 1:
            cout << "�A�O�c����������m�A�]�~���ӤJ�c\n";
            ambition+=1;
            break;
		case 2:
            cout << "�����F�q�A�J��Ʊ��ɯ�w��������A�H���D�H���`\n";
            cout << "���a�����H���ɡA�Q���o�ɵL�H���a�s\n";
			strategy+=1;
			social+=1;
			break;
		case 3:
            cout << "���m�̪��v�O�P�v�T�O���ȩ�g���C�P�o�̫إߨ}�n���Y�A���O�@�ۤv���w���B�������|���������n\n";
			social+=1;
			strategy+=1;
			break;
		case 4:
            cout << "����[��ϧA�j�T��֥[�J�}���i��|�J�쪺�v�O����\n";
			safety+=2;
			break;
		case 5:
            cout << "�Y�Y�Y�����A�׿E�_�F�ӤW�����A���A�o�]�ҩ��F�A�������Q������!\n";
			emperor+=1;
			strategy+=1;
			break;
		case 6:
            cout << "�A�u�O�Ӫ����äj�v!\n";
            cout << "�A�Φ��j�j���p���A�����h�H������P�귽�A���ٯ�O�A�����!\n";
			social+=1;
			strategy+=1;
			break;
		case 7:
		{
			random_device rd;  // �u�����H���ƺؤl
            mt19937 gen(rd()); // �����H���Ƥ���
            uniform_int_distribution<int> dist(1, 100);  // ���� 1~100 �������Ʀr

            int chance = dist(gen);  // ����H����
            if (chance <= 40)
			{
                cout << "�ӤW:�k�H�A���\�l�ޤF�ڪ��`�N�A�ӵ����A�Ʀ���A���N��������C\n";
                cout << "�z��!�ӤW�����F��!�A���ͧP��q�Ӱ����F�A�h��O�H�ٸr���x�q�C\n";
                cout << "�ɤW�Q�m���A��o�R�����a��P�v�O�A���e�ۭt�p�����m����ۻP�A���n���Y�A�A�w�O�@�H���U�A�U�H���W!\n";
                social+=1;
                ambition+=2;
                strategy+=2;
                emperor+=1;
                interaction+=1;
                safety+=2;
            }
			else
			{
                cout << "�ӤW:�A���Ӫ��ꥻ�P�ӽͧP!\n";
                cout << "�ӫһ{���A�L�z���x�A�A�D���c���m�̪��կ��A���Q�m�߷Q�A�{�b�O�̨Ϊ��ɾ��A\n";
                cout << "�O�ɭ԰����A�F�A�ַQ�Q���@�Ϧۤv�a!\n";
                social-=1;
                interaction-=2;
                safety-=1;
            }
			break;
		}
		case 8:
    		if (interaction>=3)
			{
				cout << "�A���b���c���ѽ��ת��j�U���A��G�ϩ��m�˵ۦb�A������̬y�ʡC�A�A�ש󦨬��F�ӦZ�C\n";
				cout << "�o�@�誺�v�O���A�P�쿳�ġA��P��@�ثe�ҥ������۫H�A���o�@�ɪ��Ҧ����᳣�໴���Ӿ�A\n";
				cout << "�Ҧ����D�����i�H�x���b�⤤�A�o�@�@�רs�����F�ۤv�Q�n���Ҽ�!\n";
				cout << "�A������:�ӦZ\n";
				E=true;
			}
			else
			{
		 		cout << "�Զ��z�o�A�A���չϴM�D���@�A�o�L�H�@�N�ۧU�C�̲סA�A�Q���J�N�c�A�פ�x��}�Ѯc�𤺡C\n";
		 		cout << "�������m���L�a���w���šA���ܦ��h�A�]�L�H�ݬz�C\n";
		 		cout << "�A������:�Q���J�N�c";
	 			E=true;
			}
			break;
		case 9:
		{
			random_device rd;  // �u�����H���ƺؤl
            mt19937 gen(rd()); // �����H���Ƥ���
            uniform_int_distribution<int> dist(1, 100);  // ���� 1~100 �������Ʀr

            int chance = dist(gen);  // ����H����
            if (chance<=40)
            {
                if (emperor>=4)
                {
					cout << "�A�ұo�쪺�A�ëD�ȶȬO�ӫҪ��C���A�ӬO�L��A�Ҧ��߷N���W���C\n";
                    cout << "�A���D�A�o���d�R�O�p�������o�P�öQ�A���A�P��L�񪺺aģ�Pź�ơC\n";
                    cout << "�A���b�L�����e�A�����u���L�@�ӤH�A�Ҧ������ݻP���泣�E�J�b�L���������C\n";
                    cout << "���@��A�A�L�k�ܩڤߤ����ѱj�P�����P�A�����A�J�P�ʤS�E�ʡA�o�ӥ@�ɳ��b���A�Q���@�������{�{���D���C\n";
                    cout << "�A������:�d�m\n";
					E=true;
				}
				else
				{
			 		cout << "�Զ��z�o�A�A���չϴM�D���@�A�o�L�H�@�N�ۧU�C�̲סA�A�Q���J�N�c�A�פ�x��}�Ѯc�𤺡C\n";
                    cout << "�������m���L�a���w���šA���ܦ��h�A�]�L�H�ݬz�C\n";
                    cout << "�A������:�Q���J�N�c";
			 		E=true;
				}
			}
			else
			{
                cout << "�A�B�B����A�q�����ʫʨ�󰪪��ٸ��A�o�]�@���c�ܥ��աC\n";
                cout << "�]��`�I�A�ͤk�^�W�@�J�r���A�A�����@�ġA��ӡA�`�c�����A�רs�L�H�ൽ�סC\n";
                cout << "�A������:�c�����Ѧ��`";
				E=true;
			}
			break;
		}
		default:
			cout << "�ӤH�A��X�h�A�٤F!";
			E=true;
	}
}
/*
 * �N�Ҧ����ﶵ 4 �W�ߦ��@�Ө禡�A�����ϥ� switch ����C�^�X���ԭz�C
 *
 * �ѼơG
 * - int run - ��e�^�X�ơA�ھڤ��P�^�X��X�����������y�z�üv�T����ƭȡC
 *
 *  �S�����G
 * - �Y�Ǧ^�X�]�p 4, 5, 6, 8�^�|�ھ��H�����v�M�w���P���G�C
 */
void option_D (int run)
{
	 switch(run)
	{
		case 0:
			break;
		case 2:
            cout << "�M�L�d�n���Y�����v�T��A���a��M���ӵo�i�C�����ɦ����d�m�����v�Τɦ�ֳt\n";
            cout << "���o�d�����I�A�B�v���E�P\n";
			emperor+=1;
			safety-=1;
			break;
		case 3:
			cout << "�L�c���̤j���v�O�̡A�N�|�����v�T�A���Ӫ��a��γB��\n";
			emperor+=1;
			safety-=1;
			break;
		case 4:
        {
			random_device rd;  // �u�����H���ƺؤl
    		mt19937 gen(rd()); // �����H���Ƥ���
    		uniform_int_distribution<int> dist(1, 100);  // ���� 1~100 �������Ʀr

    		int chance = dist(gen);  // ����H����
    		if (chance<=50)
    		{
    			cout << "�ӫҹ��A���@�c�������q�P��تA�A��A���n�P�ȡA�A���i��]�ҩ��F�A�o���ʹ���������q�H�ζ��p������\n";
    			emperor+=2;
    			ambition+=2;
    			strategy+=2;
			}
			else
			{
				cout << "�A�������q���V�|�F!�X��Q�m�ϧA�D��t�ߡA�A�P���m�̪����Y�c�ơA�Фp�ߤ��L�̱o�w��A�A���B�ҧħĥi�M!\n";
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
				cout << "�ӫҤ߷Q:�ڤw�g�ܤ[�S�ݹL�o�򦳭өʪ��k�l�F�A�u�O�ӻŤF�A�ӤQ�����w!\n";
				cout << "�A�ﰪ��j�P����i�{�X�A���p�����ߥH�Ψ��V������!�u�O���o���ܷ����M�w!\n";
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
					cout << "�ӫҤ߷Q:�ڤw�g�ܤ[�S�ݹL�o�򦳭өʪ��k�l�F�A�u�O�ӻŤF�A�ӤQ�����w!";
					cout << "�A�ﰪ��j�P����i�{�X�A���p�����ߥH�Ψ��V������!�u�O���o���ܷ����M�w!";
					emperor+=1;
					ambition+=2;
					strategy+=1;
				}
				else
				{
					cout << "�Ѱ�!�A�ݬݧA���F����!";
					cout << "�����󰪦쪺�L�{���A�A�޵o�F�h������ߩM�v���A�ް_�ӫҩM�Q�ڭ̪������A�A�D������P�w��!";
					cout << "�ЧֱϱϦۤv�a!";
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
				cout << "�A��o�F�L�����@�A�o���h���귽�P����A�A�i�H�p�e���U�Ӫ��p�ѤF!\n";
				safety+=1;
				ambition+=1;
				strategy+=1;
				social+=1;
			}
			else
			{
				cout << "�u���c�P�A�������ѡA�󶷺U�M���ơH�v�o���@�P�A���ġA�����@���F�A�ө۷S���i�C";
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
				 	cout << "�A���b���c���ѽ��ת��j�U���A��G�ϩ��m�˵ۦb�A������̬y�ʡC�A�A�ש󦨬��F�ӦZ�C\n";
                    cout << "�o�@�誺�v�O���A�P�쿳�ġA��P��@�ثe�ҥ������۫H�A���o�@�ɪ��Ҧ����᳣�໴���Ӿ�A\n";
                    cout << "�Ҧ����D�����i�H�x���b�⤤�A�o�@�@�רs�����F�ۤv�Q�n���Ҽ�!\n";
                    cout << "�A������:�ӦZ\n";
				 	E=true;
				}
				else
				{
				 	cout << "�A�ұo�쪺�A�ëD�ȶȬO�ӫҪ��C���A�ӬO�L��A�Ҧ��߷N���W���C\n";
                    cout << "�A���D�A�o���d�R�O�p�������o�P�öQ�A���A�P��L�񪺺aģ�Pź�ơC\n";
                    cout << "�A���b�L�����e�A�����u���L�@�ӤH�A�Ҧ������ݻP���泣�E�J�b�L���������C\n";
                    cout << "���@��A�A�L�k�ܩڤߤ����ѱj�P�����P�A�����A�J�P�ʤS�E�ʡA�o�ӥ@�ɳ��b���A�Q���@�������{�{���D���C\n";
                    cout << "�A������:�d�m\n";
				 	E=true;
				}
			}
			else
			{
				cout << "�A�b�c�����G�ä��n�����ܰ���A������o�ǳ\���d�A�o�q������Ӧh�C\n";
                cout << "��c�ʺ����ڶB�������U�t�U�P�A�Զè�ӡA�Ҧ����v�ѻP�������Ƭ��L�����ϡC\n";
                cout << "�̲סA�A�b�`�c�������q�q�׹L���Z�@�ͪ��H�A�L�H�O�_�C\n";
                cout << "�A������:�����L�_";
				E=true;
			}
			break;
	    }
		default:
			cout << "�ӤH�A��X�h�A�٤F!";
			E=true;
	}
}
/*
 * �D�禡�G�ϥ� while �j��䴩��ӹC�����y�{�A�èϥΥ��L�ȧP�_�O�_�~��i��C���C
 *
 * �D�n�y�{�G
 * 1. �b�C�^�X�}�l�ɡA�ھڷ�e�^�X�� `run` Ĳ�o���P�����M�ƥ�C
 * 2. �Ĥ��^�X�]`run == 5`�^�|�i��a������A�è̷ӥ��L�� `F` �P�_�O�_�w�F���I�C�Y��F���I�A`return true` �ñN `F` �]�� `false`�A���X�a�ϥͦ��j��A�~��D�@���C
 * 3. ��D�@��������A�̷ӥ��L�� `E` �P�_�O�_�����C���A�Y�C�������A`return true` �õ����{������C
 *
 * ��J�G
 * - `n`�]��ơ^�G���a��ܪ��ﶵ�A�ھڤ��P�ﶵ����������ާ@�C
 * - `move`�]�r�š^�G�ΨӳB�z���a���a�ϲ��ʡC
 *
 * �C����������G
 * - �� `E == true` �ɡA�C�������C
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
                cout << "�ӤH�A��X�h�A�٤F!\n";
                cout << "...�A���A�@�����|�A���ԷV�^��...\n";
                continue;
        	}
        	incident(run);

        	run++;
    	}

    return 0;
}
