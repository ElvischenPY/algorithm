#include <stdio.h>
#include <string.h>

#define FTS_UPGRADE_LOOP		30
#define FTS_MAX_POINTS_2                        		2
#define FTS_MAX_POINTS_5                        		5
#define FTS_MAX_POINTS_10                        		10
#define AUTO_CLB_NEED                           		1
#define AUTO_CLB_NONEED                         		0
#define FTS_UPGRADE_AA		0xAA
#define FTS_UPGRADE_55		0x55
#define HIDTOI2C_DISABLE					0

typedef unsigned char		u8;
typedef unsigned short		u16;
typedef unsigned int		u32;
typedef unsigned long long	u64;

struct fts_Upgrade_Info 
{
        u8 CHIP_ID;
        u8 TPD_MAX_POINTS;
        u8 AUTO_CLB;
	 u16 delay_aa;						/*delay of write FT_UPGRADE_AA */
	 u16 delay_55;						/*delay of write FT_UPGRADE_55 */
	 u8 upgrade_id_1;					/*upgrade id 1 */
	 u8 upgrade_id_2;					/*upgrade id 2 */
	 u16 delay_readid;					/*delay of read id */
	 u16 delay_erase_flash; 				/*delay of earse flash*/
};
const  struct  fts_Upgrade_Info fts_updateinfo_curr;

 struct fts_Upgrade_Info fts_updateinfo[] =
{
    {0x55,FTS_MAX_POINTS_5,AUTO_CLB_NEED,50, 30, 0x79, 0x03, 10, 2000}, //,"FT5x06"
    {0x08,FTS_MAX_POINTS_5,AUTO_CLB_NEED,50, 10, 0x79, 0x06, 100, 2000}, //,"FT5606"
	{0x0a,FTS_MAX_POINTS_5,AUTO_CLB_NEED,50, 30, 0x79, 0x07, 10, 1500}, //,"FT5x16"
	{0x06,FTS_MAX_POINTS_2,AUTO_CLB_NONEED,100, 30, 0x79, 0x08, 10, 2000}, //,"FT6x06"
	{0x36,FTS_MAX_POINTS_2,AUTO_CLB_NONEED,10, 10, 0x79, 0x18, 10, 2000}, //,"FT6x36"
	{0x55,FTS_MAX_POINTS_5,AUTO_CLB_NEED,50, 30, 0x79, 0x03, 10, 2000}, //,"FT5x06i"
	{0x14,FTS_MAX_POINTS_5,AUTO_CLB_NONEED,30, 30, 0x79, 0x11, 10, 2000}, //,"FT5336"
	{0x13,FTS_MAX_POINTS_5,AUTO_CLB_NONEED,30, 30, 0x79, 0x11, 10, 2000}, //,"FT3316"
	{0x12,FTS_MAX_POINTS_5,AUTO_CLB_NONEED,30, 30, 0x79, 0x11, 10, 2000}, //,"FT5436i"
	{0x11,FTS_MAX_POINTS_5,AUTO_CLB_NONEED,30, 30, 0x79, 0x11, 10, 2000}, //,"FT5336i"
	{0x54,FTS_MAX_POINTS_5,AUTO_CLB_NONEED,2, 2, 0x54, 0x2c, 20, 2000}, //,"FT5x46"
    {0x58,FTS_MAX_POINTS_5,AUTO_CLB_NONEED,2, 2, 0x58, 0x2c, 20, 2000},//"FT5822",
	{0x59,FTS_MAX_POINTS_10,AUTO_CLB_NONEED,30, 50, 0x79, 0x10, 1, 2000},//"FT5x26",
	{0x86,FTS_MAX_POINTS_10,AUTO_CLB_NONEED,2, 2, 0x86, 0xA6, 20, 2000},//"FT8606",
};


void fts_get_upgrade_array(void)
{
	u8 chip_id;
	u32 i;
	int ret = 0;

  struct  fts_Upgrade_Info fts_updateinfo_curr_1;
	printf("%s chip_id = %x\n", __func__, chip_id);

	chip_id = 0x54;
	printf("%s(%d) chip_id = %x\n", __func__,__LINE__,fts_updateinfo_curr->CHIP_ID);
	for(i=0;i<sizeof(fts_updateinfo)/sizeof(struct fts_Upgrade_Info);i++){
		if(chip_id==fts_updateinfo[i].CHIP_ID){
			memcpy(&fts_updateinfo_curr_1, &fts_updateinfo[i], sizeof(struct fts_Upgrade_Info));
			fts_updateinfo_curr=&fts_updateinfo_curr_1;
			break;
		}
	}
	printf("%s(%d) chip_id = %x\n", __func__,__LINE__,fts_updateinfo_curr->CHIP_ID);
	if(i >= sizeof(fts_updateinfo)/sizeof(struct fts_Upgrade_Info)){
//		memcpy(fts_updateinfo_curr, &fts_updateinfo[0], sizeof(struct fts_Upgrade_Info));
	}

	printf("%s(%d) chip_id = %x\n", __func__,__LINE__,fts_updateinfo_curr->CHIP_ID);


}

int main()
{
	printf("%s(%d) chip_id = %x\n", __func__,__LINE__,fts_updateinfo_curr->CHIP_ID);
	fts_get_upgrade_array();
	printf("%s(%d) chip_id = %x\n", __func__,__LINE__,fts_updateinfo_curr->CHIP_ID);

	fts_updateinfo_curr.CHIP_ID = 0x12;
	printf("%s(%d) chip_id = %x\n", __func__,__LINE__,fts_updateinfo_curr->CHIP_ID);
	return 0;
}






