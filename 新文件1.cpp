#include <iostream>
#include <random>  // ��{�N���H���Ʋ��ͤ覡
using namespace std;
int social=0,ambition=0,strategy=0,emperor=0,interaction=0,safety=0;
bool E=false;
//����
void scene (int run)
{
	switch(run) 
	{
		case 0:
        	cout << "�b�o�ӥR�����ѻP�v�Ѫ��j�N�c�ʤ��A�A�O�@��Q�ǥѶi�c�ӹF���ڷQ���s�H�C�H�۬ӫҵn��A�c�����U���դO�]�}�l�������ʡC�C�@��c�k�B�ӺʡB�Ʀ����m�A�L�׬O���B�����٬O�C��A���b���v�O�Ӻ����ڶB�C�b�o���v�O���x�����A�O�̪���Y�ӶդO�A�٬O�D���v�¡A�����@�u���a�H\n";
        	cout << "�b�j�N�c�ʤ��A�A�ݭn�B�δ��z�P�i��A�b�c�ʤ��B�B����A������͡A�äp�����墨�Ǧb�I��ޱ��@�����v�O�H���C�C�@�ӿ�ܡA�L�׬O�R�뱡���A�٬O���ۭI�q�A���N�M�w�A�b�o�ӵ��R���M�I���c�ʤ����R�B�C\n";
        	cout << "�Ъ`�N�A�b�o�ӥ@�ɥ�����D���N�@�P�v�T�A�����ӡA�A�e�X�^�����e�ХJ���ˬd�O�_��1.�h�l���Ÿ�(�Ҧp: �A�C .) 2.�W�L�ﶵ���Ʀr(�Ҧp�ﶵ��1-4�A�o�^��6)�A�Y�����o�͡A�i��|���N�Q����B�M�I����G�b���ݵۧA...(�Ҧp: �A�C .)�A�Y�����o�͡A�i��|���N�Q����B�M�I����G�b���ݵۧA...\n";
        	cout << "��J1-4�䤤�@�ӼƦr�H�~��C��...\n"; 
			break;
    	case 1:
        	cout << "�b�o�y�������c�����A���L�ƺس~�|�i�H�i�J�A��ܤ��P���覡�N�M�w�A�b�c���������M�R�B�C\n";
        	cout << "1.�c�k:�C�a��A�ݾa���|�ʤɡA�ͦs��O�j\n";
    		cout << "2.�Q�ڤp�j:����Y�ƨ��f�ءA�������������ؼ�\n";
    		cout << "3.����:�����ѻP��c�����A���ʥF�I��\n";
    		break;
    	case 2: 
        	cout << "�J�c��Ĥ@��ƬO�H\n";
        	cout << "����J�c�ʪ��A�A�o�O�@�ӭ��ͥB�R���D�Ԫ����ҡC��c����§���B�W�x�M�v�O���c�������͡C�C�Ӱʧ@�B�����|��A�����i��v�T�A�����ӡC�b���X�C�ӨM�w���e�A�ХJ�ӷQ�Q�p��F���������ؼСC\n";
    		cout << "1.�C�զ�ơA�קK���J�U�Ұ����C(���|�j�T�v�T�A���d�����|)\n";
    		cout << "2.�n���ڵ��c���v�Q�A��ﰪ��̡A�A���o�շ|���֡C(�b�o���i��|�j�q���)\n";
    		cout << "3.�̾a�ӺʡB�c�k�������A�����F�q�A�J��Ʊ��ɯ�w��������A�H���D�H���`�C(���a�����H���ɡA�Q���o�ɵL�H���a�s)\n";
    		cout << "4.�a�ۨ��~���l�ެӤW�A�M�L�d�n���Y�����v�T��A���a��M���ӵo�i�C�����ɦ����d�m�����v�Τɦ�ֳt�C(�o�d�����I�A�v���E�P)\n"; 
    		break;
		case 3: 
    		cout << "�P�ַd�n���Y�H\n";
        	cout << "�b�c�ʤ��A�إߨ}�n�����Y���ͦs�M�o�i�������n�C\n";
    		cout << "1.�ӺʡB�c�k: �q�`���۲`�J���������Y�M�����ӷ��C\n";
    		cout << "2.�v��: ���A���ѧ�h�����|�A�åB���A�b�v�O��������í�}�B�C�o�ǤH������������ର�A�a��í�T����ޡC\n";
    		cout << "3.���m: �o�̪��v�O�P�v�T�O���ȩ�g���C�P�o�̫إߨ}�n���Y�A���O�@�ۤv���w���B�������|���������n�C\n";
    		cout << "4.�ӫ�: �c���̤j���v�O�̡A�N�|�����v�T�A���Ӫ��a��γB�ҡC\n"; 
    		break;
		case 4: 
    		cout << "�@�����m���l�A�����A�A��ܡH\n";
        	cout << "�@�����m���l�A�����A�o�L�ìO�@�ӷ��㭷�I���]�R����O�����|�C�b�o�˪����p�U�A�A�ݭn�J�ӦҼ{�ӨM�w�O�_�[�J�o���}��C\n";
    		cout << "1.�[�J\n";
    		cout << "2.�ڵ�\n";
    		cout << "3.�[��\n";
    		cout << "4.�X��o\n"; 
    		break;
		case 5: 
    		cout << "�ӫҬ�M��A������A�A���A�סH\n";
        	cout << "�o�ѧA�b�s���(�a�ϡA�q�c��������s���)�y���a���B�A�]�\�O�Y���餤�������A�]�γ\�O�ƸѤߤ����{�e�C�ӫҨ��Ѩ��]�b���A���Z���j�ۤӻ��A�å��o�{�A�ӫұq���B�ݨ쨭��@ŧ���⯽�Ȫ��A�A����A���Ϳ���ӡC�ӧA���A�ױN�v�T�ӤW��A���A�סC\n";
    		cout << "1.�D�ʱ���\n";
    		cout << "2.�Y�Y�Y��\n";
    		cout << "3.�ڵ��A�O���Z���A���ۤv\n";
    		cout << "4.�չϿѨD�󰪦a��\n"; 
    		break;
		case 6: 
    		cout << "�ĤH�}�l�w��A�A�A�p������H\n";
    		cout << "1.�ԭ@\n";
    		cout << "2.�D�ʥX��\n";
    		cout << "3.�p�X��L���m\n";
    		cout << "4.�Q�n�ӦZ\n"; 
    		break;
		case 7: 
    		cout << "�ӫҽ絹�A�@�Ӿ��|(�ʤ�/�ʽ�)�A�����N���A�A������?\n";
    		cout << "1.����\n";
    		cout << "2.�ڵ�\n";
    		cout << "3.�ѨD��j�Q�q\n"; 
    		break;
		case 8: 
    		cout << "�ӫҨ��餣�A�A�A�����|�v�T���x�A�A�M�w?\n";
    		cout << "1.�����Ӥl\n";
    		cout << "2.����ۤv��l\n";
    		cout << "3.�p�X���v�_��\n";
    		cout << "4.�R�[����\n"; 
    		break;
		case 9: 
    		cout << "�A���{�ͦ��M���A�O�_�@�N����v�O?\n";
    		cout << "1.�O�A�b�c�ʤ���͸�\n";
    		cout << "2.�O�A���հk��\n";
    		cout << "3.�_�A�ܪ��쩳\n"; 
    		break;
		default: 
			cout << "�ӤH�A��X�h�A�٤F!";
			E=true;
	}
}
//�ﶵ1
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
			if (social>=4&&ambition>=4&&strategy>=4)
			{
				cout << "�ӦZ";
				E=true;

			}
			else if (social>=4&&ambition>=4&&strategy<4)
			{
				cout << "�d�m";
				E=true;
			}
			else 
			{
			 	cout << "�����L�_";
			 	E=true;
			} 
			break;
		case 9: 
			cout << "���A"; 
			break;
		default:
			cout << "�ӤH�A��X�h�A�٤F!";
			E=true;
	}
}
//�ﶵ2
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
		    cout << "�A�ڵ��F���m���ܽСA�o�ϱo�A�P���m�̪����Y�c�ơA���]���S���[�J�}��A���C�F���I�A�ϱo�A�����w���C\n";
		    cout << "�ӬӫҤ]�Y��A���M���A�W�[��A���n�P!\n";
			interaction-=1;
			social-=1;
			safety+=1; 
			emperor+=1;
			break;
		case 5:
		    cout << "�Y�Y�Y�����A�׿E�_�F�ӤW�����A��(?)�A�o�]�ҩ��F�A�������Q�����\!" << endl;
			emperor+=1;
			strategy+=1;
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
    		if (chance <= 30){
    			
			}else 
			{
        		cout << "�A���ѤF...\n";
    		}
    		break;
		}
		case 9:
			if (safety>=4)
			{
				cout << "���c�A���R���ͬ�\n";
				E=true;
			}
			else
			{
				cout << "�c�����Ѧ��`\n";
				E=true;
			}
			break;
		default:
			cout << "�ӤH�A��X�h�A�٤F!";
			E=true;
	}
}
//�ﶵ3
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
			strategy+=1;
			social+=1;
			break;
		case 3: 
			social+=1;
			strategy+=1;
			break;
		case 4:
		    cout << "����[��ϧA�j�T��֥[�J�}���i��|�J�쪺�v�O����\n";
			safety+=2; 
			break;
		case 5:
		    cout << "�ݰ_�ӧA�盛�d�S���򿳽�O!�O���Z���ϧA�j�{�פW�������A���ͩR�w���A���ӤW��A�����L���A�׷P�줣���A�зQ�Q�p�󭫷s����L���ߧa!\n";
			ambition-=1;
			emperor-=2;
			safety+=2;
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
    		if (chance <= 33)
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
        		cout << "�ӫһ{���A�L�z���x�A�A�D���c���m�̪��կ��A���Q�m�߷Q�A�{�b�O�̨Ϊ��ɾ��A�O�ɭ԰����A�F�A�ַQ�Q���@�Ϧۤv�a!\n";
        		social-=1;
        		interaction-=2;
        		safety-=1;
    		} 
			break;
		}
		case 8: 
    		if (interaction>=5)
			{
				cout << "�ӦZ";
				E=true;
			}
			else 
			{
		 		cout << "�Q���J�N�c";
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
					cout << "�d�m";
					E=true;
				}
				else 
				{
			 		cout << "�Q���J�N�c";
			 		E=true;
				} 
			}
			else
			{
				cout << "�c�����Ѧ��`";
				E=true; 
			}
			break;
		}
		default:
			cout << "�ӤH�A��X�h�A�٤F!";
			E=true;
	}
}
//�ﶵ4
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
				if (chance<=33)
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
				 	cout << "�ӦZ";
				 	E=true;
				} 
				else
				{
				 	cout << "�d�m";
				 	E=true;
				} 
			}
			else
			{
				cout << "�����L�_";
				E=true;
			}
			break;
	    }
		default:
			cout << "�ӤH�A��X�h�A�٤F!";
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
              cout << "�ӤH�A��X�h�A�٤F!\n";
              cout << "...�A���A�@�����|�A���ԷV�^��...\n";
              continue;
        }
        
        run++;
    }

    return 0;
}
