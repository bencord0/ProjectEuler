/*
* Copyright 2013 Ben Cordero
*
* This file is part of my ProjectEuler implementations.
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/**
 * Work out the first ten digits of the sum of the following one-hundred
 * 50-digit numbers.
 */
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include "Problem013.h"

int Problem013(void) {
	char *str;
	int i;
	mpz_t sum;
	mpz_t grid[100];
	mpz_init(sum);
mpz_init_set_str(grid[0],"37107287533902102798797998220837590246510135740250",10);
mpz_init_set_str(grid[1],"46376937677490009712648124896970078050417018260538",10);
mpz_init_set_str(grid[2],"74324986199524741059474233309513058123726617309629",10);
mpz_init_set_str(grid[3],"91942213363574161572522430563301811072406154908250",10);
mpz_init_set_str(grid[4],"23067588207539346171171980310421047513778063246676",10);
mpz_init_set_str(grid[5],"89261670696623633820136378418383684178734361726757",10);
mpz_init_set_str(grid[6],"28112879812849979408065481931592621691275889832738",10);
mpz_init_set_str(grid[7],"44274228917432520321923589422876796487670272189318",10);
mpz_init_set_str(grid[8],"47451445736001306439091167216856844588711603153276",10);
mpz_init_set_str(grid[9],"70386486105843025439939619828917593665686757934951",10);
mpz_init_set_str(grid[10],"62176457141856560629502157223196586755079324193331",10);
mpz_init_set_str(grid[11],"64906352462741904929101432445813822663347944758178",10);
mpz_init_set_str(grid[12],"92575867718337217661963751590579239728245598838407",10);
mpz_init_set_str(grid[13],"58203565325359399008402633568948830189458628227828",10);
mpz_init_set_str(grid[14],"80181199384826282014278194139940567587151170094390",10);
mpz_init_set_str(grid[15],"35398664372827112653829987240784473053190104293586",10);
mpz_init_set_str(grid[16],"86515506006295864861532075273371959191420517255829",10);
mpz_init_set_str(grid[17],"71693888707715466499115593487603532921714970056938",10);
mpz_init_set_str(grid[18],"54370070576826684624621495650076471787294438377604",10);
mpz_init_set_str(grid[19],"53282654108756828443191190634694037855217779295145",10);
mpz_init_set_str(grid[20],"36123272525000296071075082563815656710885258350721",10);
mpz_init_set_str(grid[21],"45876576172410976447339110607218265236877223636045",10);
mpz_init_set_str(grid[22],"17423706905851860660448207621209813287860733969412",10);
mpz_init_set_str(grid[23],"81142660418086830619328460811191061556940512689692",10);
mpz_init_set_str(grid[24],"51934325451728388641918047049293215058642563049483",10);
mpz_init_set_str(grid[25],"62467221648435076201727918039944693004732956340691",10);
mpz_init_set_str(grid[26],"15732444386908125794514089057706229429197107928209",10);
mpz_init_set_str(grid[27],"55037687525678773091862540744969844508330393682126",10);
mpz_init_set_str(grid[28],"18336384825330154686196124348767681297534375946515",10);
mpz_init_set_str(grid[29],"80386287592878490201521685554828717201219257766954",10);
mpz_init_set_str(grid[30],"78182833757993103614740356856449095527097864797581",10);
mpz_init_set_str(grid[31],"16726320100436897842553539920931837441497806860984",10);
mpz_init_set_str(grid[32],"48403098129077791799088218795327364475675590848030",10);
mpz_init_set_str(grid[33],"87086987551392711854517078544161852424320693150332",10);
mpz_init_set_str(grid[34],"59959406895756536782107074926966537676326235447210",10);
mpz_init_set_str(grid[35],"69793950679652694742597709739166693763042633987085",10);
mpz_init_set_str(grid[36],"41052684708299085211399427365734116182760315001271",10);
mpz_init_set_str(grid[37],"65378607361501080857009149939512557028198746004375",10);
mpz_init_set_str(grid[38],"35829035317434717326932123578154982629742552737307",10);
mpz_init_set_str(grid[39],"94953759765105305946966067683156574377167401875275",10);
mpz_init_set_str(grid[40],"88902802571733229619176668713819931811048770190271",10);
mpz_init_set_str(grid[41],"25267680276078003013678680992525463401061632866526",10);
mpz_init_set_str(grid[42],"36270218540497705585629946580636237993140746255962",10);
mpz_init_set_str(grid[43],"24074486908231174977792365466257246923322810917141",10);
mpz_init_set_str(grid[44],"91430288197103288597806669760892938638285025333403",10);
mpz_init_set_str(grid[45],"34413065578016127815921815005561868836468420090470",10);
mpz_init_set_str(grid[46],"23053081172816430487623791969842487255036638784583",10);
mpz_init_set_str(grid[47],"11487696932154902810424020138335124462181441773470",10);
mpz_init_set_str(grid[48],"63783299490636259666498587618221225225512486764533",10);
mpz_init_set_str(grid[49],"67720186971698544312419572409913959008952310058822",10);
mpz_init_set_str(grid[50],"95548255300263520781532296796249481641953868218774",10);
mpz_init_set_str(grid[51],"76085327132285723110424803456124867697064507995236",10);
mpz_init_set_str(grid[52],"37774242535411291684276865538926205024910326572967",10);
mpz_init_set_str(grid[53],"23701913275725675285653248258265463092207058596522",10);
mpz_init_set_str(grid[54],"29798860272258331913126375147341994889534765745501",10);
mpz_init_set_str(grid[55],"18495701454879288984856827726077713721403798879715",10);
mpz_init_set_str(grid[56],"38298203783031473527721580348144513491373226651381",10);
mpz_init_set_str(grid[57],"34829543829199918180278916522431027392251122869539",10);
mpz_init_set_str(grid[58],"40957953066405232632538044100059654939159879593635",10);
mpz_init_set_str(grid[59],"29746152185502371307642255121183693803580388584903",10);
mpz_init_set_str(grid[60],"41698116222072977186158236678424689157993532961922",10);
mpz_init_set_str(grid[61],"62467957194401269043877107275048102390895523597457",10);
mpz_init_set_str(grid[62],"23189706772547915061505504953922979530901129967519",10);
mpz_init_set_str(grid[63],"86188088225875314529584099251203829009407770775672",10);
mpz_init_set_str(grid[64],"11306739708304724483816533873502340845647058077308",10);
mpz_init_set_str(grid[65],"82959174767140363198008187129011875491310547126581",10);
mpz_init_set_str(grid[66],"97623331044818386269515456334926366572897563400500",10);
mpz_init_set_str(grid[67],"42846280183517070527831839425882145521227251250327",10);
mpz_init_set_str(grid[68],"55121603546981200581762165212827652751691296897789",10);
mpz_init_set_str(grid[69],"32238195734329339946437501907836945765883352399886",10);
mpz_init_set_str(grid[70],"75506164965184775180738168837861091527357929701337",10);
mpz_init_set_str(grid[71],"62177842752192623401942399639168044983993173312731",10);
mpz_init_set_str(grid[72],"32924185707147349566916674687634660915035914677504",10);
mpz_init_set_str(grid[73],"99518671430235219628894890102423325116913619626622",10);
mpz_init_set_str(grid[74],"73267460800591547471830798392868535206946944540724",10);
mpz_init_set_str(grid[75],"76841822524674417161514036427982273348055556214818",10);
mpz_init_set_str(grid[76],"97142617910342598647204516893989422179826088076852",10);
mpz_init_set_str(grid[77],"87783646182799346313767754307809363333018982642090",10);
mpz_init_set_str(grid[78],"10848802521674670883215120185883543223812876952786",10);
mpz_init_set_str(grid[79],"71329612474782464538636993009049310363619763878039",10);
mpz_init_set_str(grid[80],"62184073572399794223406235393808339651327408011116",10);
mpz_init_set_str(grid[81],"66627891981488087797941876876144230030984490851411",10);
mpz_init_set_str(grid[82],"60661826293682836764744779239180335110989069790714",10);
mpz_init_set_str(grid[83],"85786944089552990653640447425576083659976645795096",10);
mpz_init_set_str(grid[84],"66024396409905389607120198219976047599490197230297",10);
mpz_init_set_str(grid[85],"64913982680032973156037120041377903785566085089252",10);
mpz_init_set_str(grid[86],"16730939319872750275468906903707539413042652315011",10);
mpz_init_set_str(grid[87],"94809377245048795150954100921645863754710598436791",10);
mpz_init_set_str(grid[88],"78639167021187492431995700641917969777599028300699",10);
mpz_init_set_str(grid[89],"15368713711936614952811305876380278410754449733078",10);
mpz_init_set_str(grid[90],"40789923115535562561142322423255033685442488917353",10);
mpz_init_set_str(grid[91],"44889911501440648020369068063960672322193204149535",10);
mpz_init_set_str(grid[92],"41503128880339536053299340368006977710650566631954",10);
mpz_init_set_str(grid[93],"81234880673210146739058568557934581403627822703280",10);
mpz_init_set_str(grid[94],"82616570773948327592232845941706525094512325230608",10);
mpz_init_set_str(grid[95],"22918802058777319719839450180888072429661980811197",10);
mpz_init_set_str(grid[96],"77158542502016545090413245809786882778948721859617",10);
mpz_init_set_str(grid[97],"72107838435069186155435662884062257473692284509516",10);
mpz_init_set_str(grid[98],"20849603980134001723930671666823555245252804609722",10);
mpz_init_set_str(grid[99],"53503534226472524250874054075591789781264330331690",10);

	for(i=0;i<100;i++) {
		mpz_add(sum,sum,grid[i]);
	}

	str = malloc(sizeof(char) * (2+mpz_sizeinbase(sum,10)) );
	gmp_sprintf(str,"%Zd", sum);

	printf("                    ");
	for (i=0;i<10;i++) {
		printf("%c", *(str+i));
	}

	free(str);
	return 0;
}
