/***************************************************************************

    Sega Pico cartridges

***************************************************************************/

#include "driver.h"
#include "softlist.h"
#include "devices/cartslot.h"


#define PICO_ROM_LOAD( set, name, offset, length, hash )	\
SOFTWARE_START( set ) \
	ROM_REGION( 0x100000, CARTRIDGE_REGION_ROM, 0 ) \
	ROM_LOAD(name, offset, length, hash) \
SOFTWARE_END


PICO_ROM_LOAD( 101dalma1, "101 dalmatians rev 19960522 (1996)(novotrade - sega)(beta).bin",                            0x000000,  0x100000,	 CRC(2c5eee07) SHA1(1a909fb832d2b04d062f5c35f7ab1ed106573a5a) )
PICO_ROM_LOAD( 101dalma,  "101 dalmatians rev 19960531 (1996)(novotrade - sega)(beta).bin",                            0x000000,  0x100000,	 CRC(ea6fe243) SHA1(15d9a25c6350640aae1a65b41d293bde436252d9) )
PICO_ROM_LOAD( 101pikiw,  "101 piki wan-chan rev 19960817 (1996)(appaloosa interactive - sega)(jp)(beta).bin",         0x000000,  0x100000,	 CRC(cdc4dba2) SHA1(ee1b794f03ee02124e22c4050f686f4f7b6e06df) )
PICO_ROM_LOAD( poohcorn,  "a year at pooh corner (1995)(sega)(jp)(beta).bin",                                          0x000000,  0x80000,	 CRC(a47878a1) SHA1(16ab6f13bc8da6161f20600434db4111a16044d2) )
PICO_ROM_LOAD( poohcorn1, "a year at pooh corner rev 19940608 (1994)(sega)(beta).bin",                                 0x000000,  0x100000,	 CRC(d4881455) SHA1(48f104073567c96ccf8451dc5fc9c85bcbebf0ec) )
PICO_ROM_LOAD( poohcorn2, "a year at pooh corner rev 19940711 (1994)(sega)(beta).bin",                                 0x000000,  0x80000,	 CRC(640feed2) SHA1(0eacbc0dcb43de09aaa18764988056a839a3577e) )
PICO_ROM_LOAD( poohcorn3, "a year at pooh corner rev 19940721 (1994)(sega)(beta).bin",                                 0x000000,  0x80000,	 CRC(eb81b2d3) SHA1(0bec28cd6215c77e389c8d4214ab32255b26aeff) )
PICO_ROM_LOAD( poohcorn4, "a year at pooh corner rev 19940723 (1994)(sega)(beta).bin",                                 0x000000,  0x80000,	 CRC(6379c899) SHA1(819bfe1214b0ef9897380b657d264558792c4a43) )
PICO_ROM_LOAD( poohcorn5, "a year at pooh corner rev 19940725 (1994)(sega)(beta).bin",                                 0x000000,  0x7da54,	 CRC(93915a98) SHA1(d76c9d3ded9e7374c128569470f9744a9a76e308) )
PICO_ROM_LOAD( poohcorn6, "a year at pooh corner rev 19940809 (1994)(sega)(beta).bin",                                 0x000000,  0x80000,	 CRC(56ad7b29) SHA1(0cdfb0a8b07c9d0169aa70f1f9fa3520d6bd65f7) )
PICO_ROM_LOAD( berenstb,  "berenstain bears' a school day, the rev 19941220 (1995)(realtime associates - sega)(beta).bin",0x000000,  0x100000,	 CRC(2994dcee) SHA1(6019bf5829925389b44414697e7329f8c2056437) )
PICO_ROM_LOAD( berenstb1, "berenstain bears' a school day, the rev 19950106 (1995)(realtime associates - sega)(beta).bin",0x000000,  0x100000,	 CRC(5dac3ecf) SHA1(246e18fcbc271798f531944a6291ac6c9bb5840c) )
PICO_ROM_LOAD( berenstb2, "berenstain bears' a school day, the rev 19950113 (1995)(realtime associates - sega)(beta).bin",0x000000,  0xffff4,	 CRC(291aa0bd) SHA1(5677d64a2fd2ffa2baa1fd434f419407b5d47b5e) )
PICO_ROM_LOAD( berenstb3, "berenstain bears' a school day, the rev 19950116 (1995)(realtime associates - sega)(beta).bin",0x000000,  0xffff4,	 CRC(56173be7) SHA1(ccce25815ccff4468b42f8317025b5b66916645e) )
PICO_ROM_LOAD( berenstb4, "berenstain bears' a school day, the rev 19950126 (1995)(realtime associates - sega)(beta).bin",0x000000,  0xffff4,	 CRC(098c3510) SHA1(ab20a8063cd3650158a20572ae08048dc979a3e1) )
PICO_ROM_LOAD( berenstb5, "berenstain bears' a school day, the rev 19950127 (1995)(realtime associates - sega)(beta).bin",0x000000,  0xffff4,	 CRC(4709d1cf) SHA1(a6c0f0df6bb69aafcbdb49fd0ff5ef3ca7585cd9) )
PICO_ROM_LOAD( berenstb6, "berenstain bears' a school day, the rev 19950130 (1995)(realtime associates - sega)(beta).bin",0x000000,  0xffff4,	 CRC(7b53784f) SHA1(7128cea20f0695b69d552d5220097f4f4993ebef) )
PICO_ROM_LOAD( berenstb7, "berenstain bears' a school day, the rev 19950131 (1995)(realtime associates - sega)(beta).bin",0x000000,  0x100000,	 CRC(e92af9f1) SHA1(f4ae09a8a0e11cd8bec95ec3ac3908ce6da7a30f) )
PICO_ROM_LOAD( crayon,    "crayon shinchan oekaki note (1995)(bandai)(jp)(beta).bin",                                  0x000000,  0x100000,	 CRC(60656906) SHA1(1e816a3f775b2bb5a5ae9b432ee026e65dad54d6) )
PICO_ROM_LOAD( crayona,   "crayon shinchan oekaki note (1995)(bandai)(jp)(beta)[a2].bin",                              0x000000,  0x80000,	 CRC(39d4c64b) SHA1(52e115feb9d303993ca46aa36aa94a427f0ee141) )
PICO_ROM_LOAD( crayonb,   "crayon shinchan oekaki note (1995)(bandai)(jp)(beta)[a].bin",                               0x000000,  0x80000,	 CRC(843c3af4) SHA1(878733ffb5b0464f82f102f8500650bfe0b4add4) )
PICO_ROM_LOAD( dolucky,   "dolucky no oekaki house (1995)(-)(jp)(beta).bin",                                           0x000000,  0x80000,	 CRC(4ce7b75d) SHA1(aa906392c97cb12792a8cd026fdcb12d61490cf8) )
PICO_ROM_LOAD( gakkoben,  "gakken no obenkyou soft tasizan hikizan (1995)(chips - gakken)(jp)(beta).bin",              0x000000,  0x80000,	 CRC(25639a73) SHA1(d0a768236e21d05ea1734691ab9031ea7a4b3e47) )
PICO_ROM_LOAD( heiseiky,  "heisei kyouiku iinkai jr. (1995)(-)(jp)(beta).bin",                                         0x000000,  0x80000,	 CRC(6e3e29b9) SHA1(93c46585343e48e089ede74896f66b0006896c66) )
PICO_ROM_LOAD( heiseite,  "heisei ten sai baka bon minna de famiri-restutoranni-kun (1995)(-)(jp)(beta).bin",          0x000000,  0x80000,	 CRC(3656af85) SHA1(708cd58d6182a4f2448be3d2db97943c063a04f9) )
PICO_ROM_LOAD( hucklowl,  "huckle and lowly's busiest day ever rev 19940422 (1994)(realtime associates - sega)(beta).bin",0x000000,  0x100000,	 CRC(2bfb25ac) SHA1(227a2b1c36044ea4141d49eba006e927ecdd3337) )
PICO_ROM_LOAD( hucklowla, "huckle and lowly's busiest day ever rev 19940424 (1994)(realtime associates - sega)(beta).bin",0x000000,  0xfff98,	 CRC(4e032111) SHA1(7e0966ef8dfd19102a8682f1d8f6ebd41a6903f0) )
PICO_ROM_LOAD( hucklowlb, "huckle and lowly's busiest day ever rev 19940426 (1994)(realtime associates - sega)(beta).bin",0x000000,  0x100000,	 CRC(f325ab55) SHA1(efaab9cb359acb46034b5e21ce8f5a4c2f8450e5) )
PICO_ROM_LOAD( hucklowlc, "huckle and lowly's busiest day ever rev 19940426 (1994)(realtime associates - sega)(beta)[a2].bin",0x000000,  0x100000,	 CRC(fbc61621) SHA1(c6392ccd79f1140739c42e476fd0c878a3680f75) )
PICO_ROM_LOAD( hucklowld, "huckle and lowly's busiest day ever rev 19940426 (1994)(realtime associates - sega)(beta)[a].bin",0x000000,  0x100000,	 CRC(f20535c5) SHA1(f2dc08c8b0e4be40fec865e6530ffca7a474b6db) )
PICO_ROM_LOAD( hucklowle, "huckle and lowly's busiest day ever rev 19940427 (1994)(realtime associates - sega)(beta).bin",0x000000,  0x100000,	 CRC(11f32054) SHA1(310683305721f63cd2a50db9464b5cf27fd877ad) )
PICO_ROM_LOAD( hucklowlf, "huckle and lowly's busiest day ever rev 19940502 (1994)(realtime associates - sega)(beta).bin",0x000000,  0xa3088,	 CRC(265ad2d0) SHA1(de457d6e1c6037a2c165c0f65037aadd9c73042c) )
PICO_ROM_LOAD( hucklowlg, "huckle and lowly's busiest day ever rev 19940503 (1994)(realtime associates - sega)(beta)[a2].bin",0x000000,  0x100000,	 CRC(828c773f) SHA1(9c99abeac92bb7a536ea9c12c4f061ad13201261) )
PICO_ROM_LOAD( hucklowlh, "huckle and lowly's busiest day ever rev 19940503 (1994)(realtime associates - sega)(beta)[a3].bin",0x000000,  0x100000,	 CRC(3491bda7) SHA1(a8ba90e9f5071e7191c334ba1ce968fcef9d8ff8) )
PICO_ROM_LOAD( hucklowli, "huckle and lowly's busiest day ever rev 19940503 (1994)(realtime associates - sega)(beta)[a].bin",0x000000,  0x100000,	 CRC(61b37530) SHA1(10ce4256b5843c0323835a760f91d1f176e7db24) )
PICO_ROM_LOAD( hucklowlj, "huckle and lowly's busiest day ever rev 19940503 (1995)(realtime associates - sega)(beta).bin",0x000000,  0x100000,	 CRC(a79e8c5a) SHA1(baf0ec378647144948db072d32f926f188bf69e7) )
PICO_ROM_LOAD( hucklowlk, "huckle and lowly's busiest day ever rev 19940506 (1994)(realtime associates - sega)(beta).bin",0x000000,  0x100000,	 CRC(a271864c) SHA1(8acead7e6af488b320d4abb7fce51d2fa0fd49b6) )
PICO_ROM_LOAD( hucklowll, "huckle and lowly's busiest day ever rev 19940506 (1994)(realtime associates - sega)(beta)[a].bin",0x000000,  0x100000,	 CRC(98840154) SHA1(73df6e4fbf2f40efd73fa2268833c9a59e9398a1) )
PICO_ROM_LOAD( hucklowlm, "huckle and lowly's busiest day ever rev 19940509 (1994)(realtime associates - sega)(beta).bin",0x000000,  0x100000,	 CRC(a6bf6009) SHA1(930cebb1af06fff37f0b03a1f5eb695f2581ffa5) )
PICO_ROM_LOAD( hucklowln, "huckle and lowly's busiest day ever rev 19940509 (1994)(realtime associates - sega)(beta)[a2].bin",0x000000,  0x100000,	 CRC(bdd9c8fb) SHA1(99223589cb5117cd8a82d780033545dcf0e53c8a) )
PICO_ROM_LOAD( hucklowlo, "huckle and lowly's busiest day ever rev 19940509 (1994)(realtime associates - sega)(beta)[a3].bin",0x000000,  0x100000,	 CRC(9a128886) SHA1(c28b84f3ea1ada7accbc777683b55c3831c4ec9b) )
PICO_ROM_LOAD( hucklowlp, "huckle and lowly's busiest day ever rev 19940509 (1994)(realtime associates - sega)(beta)[a].bin",0x000000,  0x100000,	 CRC(782ea694) SHA1(0f17bdd2747faf6a2c3bfe7846279b6ec02b8f60) )
PICO_ROM_LOAD( hucklowlq, "huckle and lowly's busiest day ever rev 19940510 (1994)(realtime associates - sega)(beta).bin",0x000000,  0x100000,	 CRC(42007e92) SHA1(ce0b387427226baa4067d6eacebe90cef760a18e) )
PICO_ROM_LOAD( hucklowlr, "huckle and lowly's busiest day ever rev 19940919 (1994)(realtime associates - sega)(beta).bin",0x000000,  0xfff98,	 CRC(74cadb40) SHA1(7a87c09d5827df096ad8572da3a67a3913762589) )
PICO_ROM_LOAD( hucklowls, "huckle and lowly's busiest day ever rev 19941004 (1994)(realtime associates - sega)(beta).bin",0x000000,  0xfff98,	 CRC(f0d08ce0) SHA1(46213ef731dc66325e824b620e05577b1b4a9718) )
PICO_ROM_LOAD( journee,   "journee la plus occupee de huckle et lowly, la rev 19940721 (1994)(realtime associates - sega)(fr)(beta).bin",0x000000,  0xf9efc,	 CRC(026ca6f0) SHA1(0e2898a56cf47576e68db772639c23a7efcaf026) )
PICO_ROM_LOAD( kikansha,  "kikansha thomas ni notte (1995)(bandai)(jp)(beta).bin",                                     0x000000,  0x80000,	 CRC(32f926ac) SHA1(cf7cce404c013c57bfb0e80c5da3213af64dd505) )
PICO_ROM_LOAD( lionking,  "lion king, the - adventures at pride rock rev 19950419 (1995)(realtime associates - sega)(beta).bin",0x000000,  0x100000,	 CRC(97effc7b) SHA1(9df5d484be194516604b901349dee19fa30ee2f7) )
PICO_ROM_LOAD( lionking1, "lion king, the - adventures at pride rock rev 19950425 (1995)(realtime associates - sega)(beta).bin",0x000000,  0x100000,	 CRC(b948be65) SHA1(0a7a95ef14997bc617b137e4e7da5cc3762bc516) )
PICO_ROM_LOAD( lionking2, "lion king, the - adventures at pride rock rev 19950501 (1995)(realtime associates - sega)(beta).bin",0x000000,  0xfe8be,	 CRC(d5ecd5fd) SHA1(29f505bb944cec4b09e6a2baf7dd72427f9d1574) )
PICO_ROM_LOAD( lionking3, "lion king, the - adventures at pride rock rev 19950516 (1995)(realtime associates - sega)(beta).bin",0x000000,  0xfd034,	 CRC(6fbfd61b) SHA1(35b1ff9b842271055fea434406eb6d0d2dafcb0f) )
PICO_ROM_LOAD( lionking4, "lion king, the - adventures at pride rock rev 19950517 (1995)(realtime associates - sega)(beta).bin",0x000000,  0xfd034,	 CRC(f943083f) SHA1(fc2bb183b0aed8ad6134fd345d83d43fef924a27) )
PICO_ROM_LOAD( lionking5, "lion king, the - adventures at pride rock rev 19950522 (1995)(realtime associates - sega)(beta).bin",0x000000,  0x100000,	 CRC(3ad71894) SHA1(92f6f45a4f635d42824fb6fb23b34854d47cf82d) )
PICO_ROM_LOAD( lionking6, "lion king, the - adventures at pride rock rev 19950615 (1995)(realtime associates - sega)(beta).bin",0x000000,  0xfd034,	 CRC(0588d13c) SHA1(0814754b867eb61f1e546910c4fd063960a85e62) )
PICO_ROM_LOAD( lionking7, "lion king, the - adventures at pride rock rev 19950616 (1995)(realtime associates - sega)(beta).bin",0x000000,  0x100000,	 CRC(66d90805) SHA1(6f571135acf76fa540b25c1670410d5d9fe016d8) )
PICO_ROM_LOAD( magiccra,  "magic crayons (1994)(sega)(beta).bin",                                                      0x000000,  0x80000,	 CRC(f4ba1e9b) SHA1(8d77011f2349eb14b51e76c08474817a0f318f99) )
PICO_ROM_LOAD( magiccra1, "magic crayons rev 19940614 (1994)(sega)(beta).bin",                                         0x000000,  0x7dada,	 CRC(8d4c66f4) SHA1(f9f8a87a19ba36e2852f9f5c8a062345f2a4d7a6) )
PICO_ROM_LOAD( magiccra2, "magic crayons rev 19940623 (1994)(sega)(beta).bin",                                         0x000000,  0x7dcda,	 CRC(d4604e6e) SHA1(ea7f41f2e6f0a24c6c06531cb20e40139ae0efb8) )
PICO_ROM_LOAD( magiccra3, "magic crayons rev 19940630 (1994)(sega)(beta).bin",                                         0x000000,  0x80000,	 CRC(51a06b4e) SHA1(402cedcc402a72222f2e718493e38bf9a206df84) )
PICO_ROM_LOAD( magiccra4, "magic crayons rev 19940926 (1994)(sega)(beta).bin",                                         0x000000,  0x7dc96,	 CRC(579ca72b) SHA1(eb755371b32e5c83bb347942e84b3f9e5fb8fd4c) )
PICO_ROM_LOAD( magiccra5, "magic crayons rev 19941006 (1994)(sega)(beta).bin",                                         0x000000,  0x7dc96,	 CRC(864d2c7c) SHA1(718975648c1184954ed2aa6fbefc724fb99b98a5) )
PICO_ROM_LOAD( magiccra6, "magic crayons rev 19941011 (1994)(sega)(beta).bin",                                         0x000000,  0x80000,	 CRC(f9d086fd) SHA1(8e22b5d6153da0f5458a5cd38c5169baa82df540) )
PICO_ROM_LOAD( magiccra7, "magic crayons rev 19941012 (1994)(sega)(beta).bin",                                         0x000000,  0x80000,	 CRC(efa0da47) SHA1(5b234db6399a72c718bc60ff8fa6e39b88420322) )
PICO_ROM_LOAD( mathant,   "math antics with 101 dalmatians rev 19960703 (1996)(novotrade - sega)(beta).bin",           0x000000,  0x100000,	 CRC(29d31f1e) SHA1(7f8cfd2778876dd7ca03fa0a89a0da66bd7cf483) )
PICO_ROM_LOAD( mathant1,  "math antics with 101 dalmatians rev 19960705 (1996)(novotrade - sega)(beta).bin",           0x000000,  0x100000,	 CRC(3d17bfdc) SHA1(8aef447eb11567ba3663d89ad417987a6d5b8cbf) )
PICO_ROM_LOAD( mathant2,  "math antics with 101 dalmatians rev 19960718 (1996)(novotrade - sega)(beta).bin",           0x000000,  0x100000,	 CRC(849abcb2) SHA1(950888fd46a956c93baa3e938ee264b2de58055e) )
PICO_ROM_LOAD( mathant3,  "math antics with 101 dalmatians rev 19960814 (1996)(appaloosa interactive - sega)(beta).bin",0x000000,  0x100000,	 CRC(16d9431c) SHA1(e37c7b85b9c57301a9223507457ca0a78f7e4b24) )
PICO_ROM_LOAD( mathant4,  "math antics with 101 dalmatians rev 19960816 (1996)(appaloosa interactive - sega)(beta).bin",0x000000,  0x100000,	 CRC(f0269662) SHA1(7f7186de1a79427078a682aeca222e7df9994ffc) )
PICO_ROM_LOAD( mathant5,  "math antics with 101 dalmatians rev 19960817 (1996)(appaloosa interactive - sega)(beta).bin",0x000000,  0x100000,	 CRC(602e237a) SHA1(915d44cbc0d0f04be485609c1367a1d47f140942) )
PICO_ROM_LOAD( mathant6,  "math antics with 101 dalmatians rev 19960817 (1996)(appaloosa interactive - sega)(beta)[a].bin",0x000000,  0x100000,	 CRC(d271f727) SHA1(bbbb351396ae9c636092efc6780dd1f80f4ca854) )
PICO_ROM_LOAD( mickblst,  "mickey's blast into the past (1994)(sega)(us).bin",                                         0x000000,  0x80000,	 CRC(2628f6ef) SHA1(1d04a40d353f71061b206d893d2d8e7864a2faee) )
PICO_ROM_LOAD( mickblst1, "mickey's blast into the past rev 19940608 (1994)(sega)(beta).bin",                          0x000000,  0x100000,	 CRC(a9dbf978) SHA1(f6fba5c1992a4b5f7109845706f02a76184bf3ba) )
PICO_ROM_LOAD( mickblst2, "mickey's blast into the past rev 19940721 (1994)(sega)(beta).bin",                          0x000000,  0x100000,	 CRC(a0ae9860) SHA1(595c464b9aa104db104a58f9b5d73f006e438c9f) )
PICO_ROM_LOAD( mickblst3, "mickey's blast into the past rev 19940723 (1994)(sega)(beta).bin",                          0x000000,  0x100000,	 CRC(d78baabc) SHA1(baf6ccf28557b148f984ed58cafca1c55496e245) )
PICO_ROM_LOAD( mickblst4, "mickey's blast into the past rev 19940725 (1994)(sega)(beta).bin",                          0x000000,  0x80000,	 CRC(1a2760fe) SHA1(d19812e54b2a0c6b086bea861c4209841eb0adac) )
PICO_ROM_LOAD( mickblst5, "mickey's blast into the past rev 19940801 (1994)(sega)(beta).bin",                          0x000000,  0x80000,	 CRC(90b047f6) SHA1(8596cdb62ff03a2f602344a16b61a1f487fa7c96) )
PICO_ROM_LOAD( mickblst6, "mickey's blast into the past rev 19940809 (1994)(sega)(beta).bin",                          0x000000,  0x80000,	 CRC(08f46903) SHA1(c0414c1524567fef2ddbff1762b8cce9803b81a0) )
PICO_ROM_LOAD( musiczoo,  "musical zoo rev 19941220 (1995)(sega)(beta).bin",                                           0x000000,  0x7ffce,	 CRC(f3f402a1) SHA1(7be6d664097d8608a3ebb0513d83e6c55692b5f8) )
PICO_ROM_LOAD( musiczoo1, "musical zoo rev 19950104 (1995)(sega)(beta).bin",                                           0x000000,  0x7ef38,	 CRC(1c5ddba2) SHA1(e1cdf0b23c09b3ebe74032d533aeb4be4c495a2a) )
PICO_ROM_LOAD( musiczoo2, "musical zoo rev 19950105 (1995)(sega)(beta).bin",                                           0x000000,  0x7ef38,	 CRC(5591682a) SHA1(9573036713284a579e3df4506b70f03e9cf224e8) )
PICO_ROM_LOAD( musiczoo3, "musical zoo rev 19950208 (1995)(sega)(beta).bin",                                           0x000000,  0x80000,	 CRC(7bb5a2a0) SHA1(a0f69509ac85a761b1f52b752608c9ac1806dea8) )
PICO_ROM_LOAD( musiczoo4, "musical zoo rev 19950209 (1995)(sega)(beta).bin",                                           0x000000,  0x7ef38,	 CRC(7fda0399) SHA1(62e5e5d86d6e9854c9498af44235f4d205c66f14) )
PICO_ROM_LOAD( musiczoo5, "musical zoo rev 19950217 (1995)(sega)(beta).bin",                                           0x000000,  0x80000,	 CRC(35add3d0) SHA1(a9f0f50c0631c4be34b6e71f76d67ef156ac2552) )
PICO_ROM_LOAD( musiczoo6, "musical zoo rev 19950217 (1995)(sega)(beta)[a].bin",                                        0x000000,  0x7ef38,	 CRC(6159cbe2) SHA1(16650fa84e5fcb4ffaf9a8ae4abbeb5920ef41c4) )
PICO_ROM_LOAD( nipponmb,  "nippon no mukasi banasi (1994)(-)(jp)(beta).bin",                                           0x000000,  0x80000,	 CRC(b62514d0) SHA1(5c128fcc3ce49434e1e3c834a9fcec7b28c5480e) )
PICO_ROM_LOAD( penguki,   "pengin ukiuki bi kkurisuizokukan meiropazuru rev 19950210 (1994)(sega)(jp)(beta).bin",      0x000000,  0x100000,	 CRC(a4a143cb) SHA1(a17a6524f382b771f4f7ac1f46d7e45836300dda) )
PICO_ROM_LOAD( pepepuzl,  "pepe's puzzles rev 19950218 (1995)(sega)(beta).bin",                                        0x000000,  0x934fc,	 CRC(f32f45e5) SHA1(26900e4f0a7b7c25b6acdc33a1a7c819fe1a543a) )
PICO_ROM_LOAD( pepepuzl1, "pepe's puzzles rev 19950220 (1995)(sega)(beta).bin",                                        0x000000,  0x84dfe,	 CRC(e0618f30) SHA1(493e165f8bcf98f98039b9c56d4a8dcf744cb178) )
PICO_ROM_LOAD( pepepuzl2, "pepe's puzzles rev 19950224 (1995)(sega)(beta).bin",                                        0x000000,  0x7fe9a,	 CRC(e72d9d76) SHA1(4f91ed645a177d41ff145a9b4b4a7024ea9025e5) )
PICO_ROM_LOAD( pbasebal,  "pico baseball (1994)(sega)(jp)(beta).bin",                                                  0x000000,  0x100000,	 CRC(a9802c1e) SHA1(e966e16409bfeaa369362625c59aab216b65b6c6) )
PICO_ROM_LOAD( psoccer,   "pico soccer mezase soccer senshu (1995)(sega)(jp)(beta).bin",                               0x000000,  0x80000,	 CRC(d9849eb8) SHA1(ba61a1c98aa5d03958ba745282086637680b13b2) )
PICO_ROM_LOAD( pstoryw,   "pico storyware sampler rev 19960607 (1996)(novotrade - sega)(beta).bin",                    0x000000,  0x100000,	 CRC(3cccf1d5) SHA1(9eb71e27714efa060d1d70753376f5e4ba7c203c) )
PICO_ROM_LOAD( pstoryw1,  "pico storyware sampler rev 19960614 (1996)(novotrade - sega)(beta).bin",                    0x000000,  0x100000,	 CRC(fa847f2c) SHA1(a18ecc5e20d1f1c076ac76b77e2258e8045968f1) )
PICO_ROM_LOAD( pstoryw2,  "pico storyware sampler rev 19960625 (1996)(novotrade - sega)(beta).bin",                    0x000000,  0x100000,	 CRC(85c4f26b) SHA1(d3342d20002fed586b43e26b29aefe15138d98ae) )
PICO_ROM_LOAD( snoopy,    "snoopy no gakugeikai (1995)(sega)(jp)(beta).bin",                                           0x000000,  0x80000,	 CRC(b76cd97c) SHA1(6d6b49249cd4513d59e1c863fed5f273113d7e9b) )
PICO_ROM_LOAD( sonicgam,  "sonic the hedgehog's gameworld (1996)(sega)(us).bin",                                       0x000000,  0x80000,	 CRC(e472a795) SHA1(839d8be99eabf371bb992166471c877db6f6e265) )
PICO_ROM_LOAD( sonicgam1, "sonic the hedgehog's gameworld rev 19960701-1105 (1996)(sega)(us)(beta).bin",               0x000000,  0x80000,	 CRC(ddcdf94b) SHA1(7ebab6cd9fc42a598082f2ab442700b414e41d9b) )
PICO_ROM_LOAD( sonicgam2, "sonic the hedgehog's gameworld rev 19960719-0127 (1996)(sega)(us)(beta).bin",               0x000000,  0x80000,	 CRC(ef774132) SHA1(3a6dc10517df2d037f716e59c13675bebf0e4246) )
PICO_ROM_LOAD( sonicgam3, "sonic the hedgehog's gameworld rev 19960802-0808 (1996)(sega)(us)(beta).bin",               0x000000,  0x80000,	 CRC(c2cbfe99) SHA1(c0d0eb5db0d34aa75f9be68d75f3b99d0aa2e193) )
PICO_ROM_LOAD( sonicgam4, "sonic the hedgehog's gameworld rev 19960808-0746 (1996)(sega)(us)(beta).bin",               0x000000,  0x80000,	 CRC(4363a1e2) SHA1(935b925c7a6ed36519b756f33aa2ce2240610471) )
PICO_ROM_LOAD( tailsmm,   "tails and the music maker rev 0608-19940608-1655 (1994)(sega)(beta).bin",                   0x000000,  0x80000,	 CRC(f83ec5e8) SHA1(39914965a38350b1bef720d39576d20943e8e4a4) )
PICO_ROM_LOAD( tailsmm1,  "tails and the music maker rev 0623-19940624-0755 (1994)(sega)(beta).bin",                   0x000000,  0x80000,	 CRC(17a8af59) SHA1(e7e69600262eda55a9be6bde248c6f9401d5833f) )
PICO_ROM_LOAD( tailsmm2,  "tails and the music maker rev 0722-19940722-2149 (1994)(sega)(beta).bin",                   0x000000,  0x80000,	 CRC(f8246157) SHA1(4f011b6055e484ddfe81acd03da8fff436b824f2) )
PICO_ROM_LOAD( tailsmm3,  "tails and the music maker rev 0725-19940626-1044 (1994)(sega)(beta).bin",                   0x000000,  0x78e16,	 CRC(ebbae9ce) SHA1(02dbbf88a190f6c068d3f4e39488010cd2a2601a) )
PICO_ROM_LOAD( tailsmm4,  "tails and the music maker rev 0927-19940927-1420 (1994)(sega)(beta).bin",                   0x000000,  0x78e56,	 CRC(beb97cf3) SHA1(3b6b392f5845a61f018d8edb5121b293ab1f32c9) )
PICO_ROM_LOAD( tailsmm5,  "tails and the music maker rev 1004-19941005-1255 (1994)(sega)(beta).bin",                   0x000000,  0x78e56,	 CRC(57714ba7) SHA1(3dfb122ab384847712dbd3fd41c6509f7d19c363) )
PICO_ROM_LOAD( tailsmm6,  "tails and the music maker rev 701b-19940702-1716 (1994)(sega)(beta).bin",                   0x000000,  0x80000,	 CRC(982154ab) SHA1(807ee1ed88ffdd780754043d836a848864155844) )


SOFTWARE_LIST_START( pico_cart )
	SOFTWARE( 101dalma1, 101dalma, 1996, "Sega", "101 Dalmatians (Prototype, 19960522)", 0, 0 )
	SOFTWARE( 101dalma,  0,        1996, "Sega", "101 Dalmatians (Prototype, 19960531)", 0, 0 )
	SOFTWARE( 101pikiw,  0,        1996, "Sega", "101 piki wan-chan (Jpn, Prototype, 19960817)", 0, 0 )
	SOFTWARE( poohcorn,  0,        1995, "Sega", "A Year At Pooh Corner (Jpn, Prototype)", 0, 0 )
	SOFTWARE( poohcorn1, poohcorn, 1994, "Sega", "A Year At Pooh Corner (Prototype, 19940608)", 0, 0 )
	SOFTWARE( poohcorn2, poohcorn, 1994, "Sega", "A Year At Pooh Corner (Prototype, 19940711)", 0, 0 )
	SOFTWARE( poohcorn3, poohcorn, 1994, "Sega", "A Year At Pooh Corner (Prototype, 19940721)", 0, 0 )
	SOFTWARE( poohcorn4, poohcorn, 1994, "Sega", "A Year At Pooh Corner (Prototype, 19940723)", 0, 0 )
	SOFTWARE( poohcorn5, poohcorn, 1994, "Sega", "A Year At Pooh Corner (Prototype, 19940725)", 0, 0 )
	SOFTWARE( poohcorn6, poohcorn, 1994, "Sega", "A Year At Pooh Corner (Prototype, 19940809)", 0, 0 )
	SOFTWARE( berenstb,  0,        1995, "Sega", "The Berenstain Bears' A School Day (Prototype, 19941220)", 0, 0 )
	SOFTWARE( berenstb1, berenstb, 1995, "Sega", "The Berenstain Bears' A School Day (Prototype, 19950106)", 0, 0 )
	SOFTWARE( berenstb2, berenstb, 1995, "Sega", "The Berenstain Bears' A School Day (Prototype, 19950113)", 0, 0 )
	SOFTWARE( berenstb3, berenstb, 1995, "Sega", "The Berenstain Bears' A School Day (Prototype, 19950116)", 0, 0 )
	SOFTWARE( berenstb4, berenstb, 1995, "Sega", "The Berenstain Bears' A School Day (Prototype, 19950126)", 0, 0 )
	SOFTWARE( berenstb5, berenstb, 1995, "Sega", "The Berenstain Bears' A School Day (Prototype, 19950127)", 0, 0 )
	SOFTWARE( berenstb6, berenstb, 1995, "Sega", "The Berenstain Bears' A School Day (Prototype, 19950130)", 0, 0 )
	SOFTWARE( berenstb7, berenstb, 1995, "Sega", "The Berenstain Bears' A School Day (Prototype, 19950131)", 0, 0 )
	SOFTWARE( crayon,    0,        1995, "Bandai", "Crayon Shinchan Oekaki Note (Jpn, Prototype)", 0, 0 )
	SOFTWARE( crayona,   crayon,   1995, "Bandai", "Crayon Shinchan Oekaki Note (Jpn, Prototype Alt 2)", 0, 0 )
	SOFTWARE( crayonb,   crayon,   1995, "Bandai", "Crayon Shinchan Oekaki Note (Jpn, Prototype Alt)", 0, 0 )
	SOFTWARE( dolucky,   0,        1995, "<unknown>", "Dolucky no Oekaki House (Jpn, Prototype)", 0, 0 )
	SOFTWARE( gakkoben,  0,        1995, "Gakken", "Gakken no Obenkyou Soft Tasizan Hikizan (Jpn, Prototype)", 0, 0 )
	SOFTWARE( heiseiky,  0,        1995, "<unknown>", "Heisei Kyouiku Iinkai Jr. (Jpn, Prototype)", 0, 0 )
	SOFTWARE( heiseite,  0,        1995, "<unknown>", "Heisei Ten Sai Baka Bon Minna de Famiri-Restutoranni-Kun (Jpn, Prototype)", 0, 0 )
	SOFTWARE( hucklowl,  0,        1994, "Sega", "Huckle and Lowly's Busiest Day Ever (Prototype, 19940422)", 0, 0 )
	SOFTWARE( hucklowla, hucklowl, 1994, "Sega", "Huckle and Lowly's Busiest Day Ever (Prototype, 19940424)", 0, 0 )
	SOFTWARE( hucklowlb, hucklowl, 1994, "Sega", "Huckle and Lowly's Busiest Day Ever (Prototype, 19940426)", 0, 0 )
	SOFTWARE( hucklowlc, hucklowl, 1994, "Sega", "Huckle and Lowly's Busiest Day Ever (Prototype, 19940426 Alt)", 0, 0 )
	SOFTWARE( hucklowld, hucklowl, 1994, "Sega", "Huckle and Lowly's Busiest Day Ever (Prototype, 19940426 Alt 2)", 0, 0 )
	SOFTWARE( hucklowle, hucklowl, 1994, "Sega", "Huckle and Lowly's Busiest Day Ever (Prototype, 19940427)", 0, 0 )
	SOFTWARE( hucklowlf, hucklowl, 1994, "Sega", "Huckle and Lowly's Busiest Day Ever (Prototype, 19940502)", 0, 0 )
	SOFTWARE( hucklowlg, hucklowl, 1994, "Sega", "Huckle and Lowly's Busiest Day Ever (Prototype, 19940503 Alt 2)", 0, 0 )
	SOFTWARE( hucklowlh, hucklowl, 1994, "Sega", "Huckle and Lowly's Busiest Day Ever (Prototype, 19940503 Alt 3)", 0, 0 )
	SOFTWARE( hucklowli, hucklowl, 1994, "Sega", "Huckle and Lowly's Busiest Day Ever (Prototype, 19940503 Alt)", 0, 0 )
	SOFTWARE( hucklowlj, hucklowl, 1994, "Sega", "Huckle and Lowly's Busiest Day Ever (Prototype, 19940503)", 0, 0 )
	SOFTWARE( hucklowlk, hucklowl, 1994, "Sega", "Huckle and Lowly's Busiest Day Ever (Prototype, 19940506)", 0, 0 )
	SOFTWARE( hucklowll, hucklowl, 1994, "Sega", "Huckle and Lowly's Busiest Day Ever (Prototype, 19940506 Alt)", 0, 0 )
	SOFTWARE( hucklowlm, hucklowl, 1994, "Sega", "Huckle and Lowly's Busiest Day Ever (Prototype, 19940509)", 0, 0 )
	SOFTWARE( hucklowln, hucklowl, 1994, "Sega", "Huckle and Lowly's Busiest Day Ever (Prototype, 19940509 Alt 2)", 0, 0 )
	SOFTWARE( hucklowlo, hucklowl, 1994, "Sega", "Huckle and Lowly's Busiest Day Ever (Prototype, 19940509 Alt 3)", 0, 0 )
	SOFTWARE( hucklowlp, hucklowl, 1994, "Sega", "Huckle and Lowly's Busiest Day Ever (Prototype, 19940509 Alt)", 0, 0 )
	SOFTWARE( hucklowlq, hucklowl, 1994, "Sega", "Huckle and Lowly's Busiest Day Ever (Prototype, 19940510)", 0, 0 )
	SOFTWARE( hucklowlr, hucklowl, 1994, "Sega", "Huckle and Lowly's Busiest Day Ever (Prototype, 19940919)", 0, 0 )
	SOFTWARE( hucklowls, hucklowl, 1994, "Sega", "Huckle and Lowly's Busiest Day Ever (Prototype, 19941004)", 0, 0 )
	SOFTWARE( journee,   hucklowl, 1994, "Sega", "La Journee La Plus Occupee de Huckle et Lowly (France, Prototype, 19940721)", 0, 0 )
	SOFTWARE( kikansha,  0,        1995, "Bandai", "Kikansha Thomas Ni Notte (Jpn, Prototype)", 0, 0 )
	SOFTWARE( lionking,  0,        1995, "Sega", "The Lion King - Adventures At Pride Rock (Prototype, 19950419)", 0, 0 )
	SOFTWARE( lionking1, lionking, 1995, "Sega", "The Lion King - Adventures At Pride Rock (Prototype, 19950425)", 0, 0 )
	SOFTWARE( lionking2, lionking, 1995, "Sega", "The Lion King - Adventures At Pride Rock (Prototype, 19950501)", 0, 0 )
	SOFTWARE( lionking3, lionking, 1995, "Sega", "The Lion King - Adventures At Pride Rock (Prototype, 19950516)", 0, 0 )
	SOFTWARE( lionking4, lionking, 1995, "Sega", "The Lion King - Adventures At Pride Rock (Prototype, 19950517)", 0, 0 )
	SOFTWARE( lionking5, lionking, 1995, "Sega", "The Lion King - Adventures At Pride Rock (Prototype, 19950522)", 0, 0 )
	SOFTWARE( lionking6, lionking, 1995, "Sega", "The Lion King - Adventures At Pride Rock (Prototype, 19950615)", 0, 0 )
	SOFTWARE( lionking7, lionking, 1995, "Sega", "The Lion King - Adventures At Pride Rock (Prototype, 19950616)", 0, 0 )
	SOFTWARE( magiccra,  0,        1994, "Sega", "Magic Crayons (Prototype)", 0, 0 )
	SOFTWARE( magiccra1, magiccra, 1994, "Sega", "Magic Crayons (Prototype, 19940614)", 0, 0 )
	SOFTWARE( magiccra2, magiccra, 1994, "Sega", "Magic Crayons (Prototype, 19940623)", 0, 0 )
	SOFTWARE( magiccra3, magiccra, 1994, "Sega", "Magic Crayons (Prototype, 19940630)", 0, 0 )
	SOFTWARE( magiccra4, magiccra, 1994, "Sega", "Magic Crayons (Prototype, 19940926)", 0, 0 )
	SOFTWARE( magiccra5, magiccra, 1994, "Sega", "Magic Crayons (Prototype, 19941006)", 0, 0 )
	SOFTWARE( magiccra6, magiccra, 1994, "Sega", "Magic Crayons (Prototype, 19941011)", 0, 0 )
	SOFTWARE( magiccra7, magiccra, 1994, "Sega", "Magic Crayons (Prototype, 19941012)", 0, 0 )
	SOFTWARE( mathant,   0,        1996, "Sega", "Math Antics With 101 Dalmatians (Prototype, 19960703)", 0, 0 )
	SOFTWARE( mathant1,  mathant,  1996, "Sega", "Math Antics With 101 Dalmatians (Prototype, 19960705)", 0, 0 )
	SOFTWARE( mathant2,  mathant,  1996, "Sega", "Math Antics With 101 Dalmatians (Prototype, 19960718)", 0, 0 )
	SOFTWARE( mathant3,  mathant,  1996, "Sega", "Math Antics With 101 Dalmatians (Prototype, 19960814)", 0, 0 )
	SOFTWARE( mathant4,  mathant,  1996, "Sega", "Math Antics With 101 Dalmatians (Prototype, 19960816)", 0, 0 )
	SOFTWARE( mathant5,  mathant,  1996, "Sega", "Math Antics With 101 Dalmatians (Prototype, 19960817)", 0, 0 )
	SOFTWARE( mathant6,  mathant,  1996, "Sega", "Math Antics With 101 Dalmatians (Prototype, 19960817 Alt)", 0, 0 )
	SOFTWARE( mickblst,  0,        1994, "Sega", "Mickey's Blast Into the Past (USA)", 0, 0 )
	SOFTWARE( mickblst1, mickblst, 1994, "Sega", "Mickey's Blast Into the Past (Prototype, 19940608)", 0, 0 )
	SOFTWARE( mickblst2, mickblst, 1994, "Sega", "Mickey's Blast Into the Past (Prototype, 19940721)", 0, 0 )
	SOFTWARE( mickblst3, mickblst, 1994, "Sega", "Mickey's Blast Into the Past (Prototype, 19940723)", 0, 0 )
	SOFTWARE( mickblst4, mickblst, 1994, "Sega", "Mickey's Blast Into the Past (Prototype, 19940725)", 0, 0 )
	SOFTWARE( mickblst5, mickblst, 1994, "Sega", "Mickey's Blast Into the Past (Prototype, 19940801)", 0, 0 )
	SOFTWARE( mickblst6, mickblst, 1994, "Sega", "Mickey's Blast Into the Past (Prototype, 19940809)", 0, 0 )
	SOFTWARE( musiczoo,  0,        1995, "Sega", "Musical Zoo (Prototype, 19941220)", 0, 0 )
	SOFTWARE( musiczoo1, musiczoo, 1995, "Sega", "Musical Zoo (Prototype, 19950104)", 0, 0 )
	SOFTWARE( musiczoo2, musiczoo, 1995, "Sega", "Musical Zoo (Prototype, 19950105)", 0, 0 )
	SOFTWARE( musiczoo3, musiczoo, 1995, "Sega", "Musical Zoo (Prototype, 19950208)", 0, 0 )
	SOFTWARE( musiczoo4, musiczoo, 1995, "Sega", "Musical Zoo (Prototype, 19950209)", 0, 0 )
	SOFTWARE( musiczoo5, musiczoo, 1995, "Sega", "Musical Zoo (Prototype, 19950217)", 0, 0 )
	SOFTWARE( musiczoo6, musiczoo, 1995, "Sega", "Musical Zoo (Prototype, 19950217 Alt)", 0, 0 )
	SOFTWARE( nipponmb,  0,        1995, "Bandai", "Nippon no Mukasi Banasi (Jpn, Prototype)", 0, 0 )
	SOFTWARE( penguki,   0,        1995, "Sega", "Pengin Ukiuki Bi Kkurisuizokukan Meiropazuru (Jpn, Prototype, 19950210)", 0, 0 )
	SOFTWARE( pepepuzl,  0,        1995, "Sega", "Pepe's Puzzles (Prototype, 19950218)", 0, 0 )
	SOFTWARE( pepepuzl1, pepepuzl, 1995, "Sega", "Pepe's Puzzles (Prototype, 19950220)", 0, 0 )
	SOFTWARE( pepepuzl2, pepepuzl, 1995, "Sega", "Pepe's Puzzles (Prototype, 19950224)", 0, 0 )
	SOFTWARE( pbasebal,  0,        1994, "Sega", "Pico Baseball (Jpn, Prototype)", 0, 0 )
	SOFTWARE( psoccer,   0,        1995, "Sega", "Pico Soccer Mezase Soccer Senshu (Jpn, Prototype)", 0, 0 )
	SOFTWARE( pstoryw,   0,        1996, "Sega", "Pico Storyware Sampler (Prototype, 19960607)", 0, 0 )
	SOFTWARE( pstoryw1,  pstoryw,  1996, "Sega", "Pico Storyware Sampler (Prototype, 19960614)", 0, 0 )
	SOFTWARE( pstoryw2,  pstoryw,  1996, "Sega", "Pico Storyware Sampler (Prototype, 19960625)", 0, 0 )
	SOFTWARE( snoopy,    0,        1995, "Sega", "Snoopy no Gakugeikai (Jpn, Prototype)", 0, 0 )
	SOFTWARE( sonicgam,  0,        1996, "Sega", "Sonic the Hedgehog's Gameworld (USA)", 0, 0 )
	SOFTWARE( sonicgam1, sonicgam, 1996, "Sega", "Sonic the Hedgehog's Gameworld (USA, Prototype, 19960701-1105)", 0, 0 )
	SOFTWARE( sonicgam2, sonicgam, 1996, "Sega", "Sonic the Hedgehog's Gameworld (USA, Prototype, 19960719-0127)", 0, 0 )
	SOFTWARE( sonicgam3, sonicgam, 1996, "Sega", "Sonic the Hedgehog's Gameworld (USA, Prototype, 19960802-0808)", 0, 0 )
	SOFTWARE( sonicgam4, sonicgam, 1996, "Sega", "Sonic the Hedgehog's Gameworld (USA, Prototype, 19960808-0746)", 0, 0 )
	SOFTWARE( tailsmm,   0,        1994, "Sega", "Tails and the Music Maker (Prototype, 0608-19940608-1655)", 0, 0 )
	SOFTWARE( tailsmm1,  tailsmm,  1994, "Sega", "Tails and the Music Maker (Prototype, 0623-19940624-0755)", 0, 0 )
	SOFTWARE( tailsmm2,  tailsmm,  1994, "Sega", "Tails and the Music Maker (Prototype, 0722-19940722-2149)", 0, 0 )
	SOFTWARE( tailsmm3,  tailsmm,  1994, "Sega", "Tails and the Music Maker (Prototype, 0725-19940626-1044)", 0, 0 )
	SOFTWARE( tailsmm4,  tailsmm,  1994, "Sega", "Tails and the Music Maker (Prototype, 0927-19940927-1420)", 0, 0 )
	SOFTWARE( tailsmm5,  tailsmm,  1994, "Sega", "Tails and the Music Maker (Prototype, 1004-19941005-1255)", 0, 0 )
	SOFTWARE( tailsmm6,  tailsmm,  1994, "Sega", "Tails and the Music Maker (Prototype, 701B-19940702-1716)", 0, 0 )
SOFTWARE_LIST_END


SOFTWARE_LIST( pico_cart,  "Sega Pico cartridges" )
