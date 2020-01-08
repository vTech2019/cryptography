#include "DataEncryptionStandardDebug.h"

//Primitive Name : Des

//================== =
//Key size : 64 bits
//Block size : 64 bits


struct DES_test DES_test_vector[] = {
{
.key = 0x8000000000000000,
.plain = 0x0000000000000000,
.cipher = 0x95A8D72813DAA94D,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0xF749E1F8DEFAF605,
.iterated_1000_times = 0xF396DD0B33D04244
},

{
.key = 0x4000000000000000,
.plain = 0x0000000000000000,
.cipher = 0x0EEC1487DD8C26D5,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0xE5BEE86B600F3B48,
.iterated_1000_times = 0x1D5931D700EF4E15
},

{
.key = 0x2000000000000000,
.plain = 0x0000000000000000,
.cipher = 0x7AD16FFB79C45926,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0xC4B51BB0A1E0DF57,
.iterated_1000_times = 0xB2D1B91E994BA5FF
},

{
.key = 0x1000000000000000,
.plain = 0x0000000000000000,
.cipher = 0xD3746294CA6A6CF3,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x0008AEE9CDC85FC6,
.iterated_1000_times = 0x984080D72E08BB81
},

{
.key = 0x0800000000000000,
.plain = 0x0000000000000000,
.cipher = 0x809F5F873C1FD761,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x30C31E1B78DEF2FA,
.iterated_1000_times = 0x17FD838EC9AAE568
},

{
.key = 0x0400000000000000,
.plain = 0x0000000000000000,
.cipher = 0xC02FAFFEC989D1FC,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x712D9B9482FFA66E,
.iterated_1000_times = 0x7D50B7C12F4EE231
},

{
.key = 0x0200000000000000,
.plain = 0x0000000000000000,
.cipher = 0x4615AA1D33E72F10,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x8D19263ED8C900E9,
.iterated_1000_times = 0x4BEB4AAC95FEC41C
},

{
.key = 0x0100000000000000,
.plain = 0x0000000000000000,
.cipher = 0x8CA64DE9C1B123A7,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x0000000000000000,
.iterated_1000_times = 0x0000000000000000
},

{
.key = 0x0080000000000000,
.plain = 0x0000000000000000,
.cipher = 0x2055123350C00858,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0xB36B590CD5B96C7A,
.iterated_1000_times = 0x27096529FD13E6D8
},

{
.key = 0x0040000000000000,
.plain = 0x0000000000000000,
.cipher = 0xDF3B99D6577397C8,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0xF39EADDACB2F57DE,
.iterated_1000_times = 0x38C1A175C83C43D5
},

{
.key = 0x0020000000000000,
.plain = 0x0000000000000000,
.cipher = 0x31FE17369B5288C9,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x148BE77FD6464AB1,
.iterated_1000_times = 0x79594476AE766731
},

{
.key = 0x0010000000000000,
.plain = 0x0000000000000000,
.cipher = 0xDFDD3CC64DAE1642,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0xF778BB09A9867BA9,
.iterated_1000_times = 0xD3EB89C029543B2A
},

{
.key = 0x0008000000000000,
.plain = 0x0000000000000000,
.cipher = 0x178C83CE2B399D94,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x73EED5A7A0F4934D,
.iterated_1000_times = 0x49438FF2A3AFCB5B
},

{
.key = 0x0004000000000000,
.plain = 0x0000000000000000,
.cipher = 0x50F636324A9B7F80,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x2FAFD56439DE7A02,
.iterated_1000_times = 0xCCC8DE0B9AA79C66
},

{
.key = 0x0002000000000000,
.plain = 0x0000000000000000,
.cipher = 0xA8468EE3BC18F06D,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0xEFAE2347FDDEFA73,
.iterated_1000_times = 0xB4023FD4512F7716
},

{
.key = 0x0001000000000000,
.plain = 0x0000000000000000,
.cipher = 0x8CA64DE9C1B123A7,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x0000000000000000,
.iterated_1000_times = 0x0000000000000000
},

{
.key = 0x0000800000000000,
.plain = 0x0000000000000000,
.cipher = 0xA2DC9E92FD3CDE92,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x73BE6AB337CEEEB0,
.iterated_1000_times = 0x968DF24C0DE982AD
},

{
.key = 0x0000400000000000,
.plain = 0x0000000000000000,
.cipher = 0xCAC09F797D031287,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x59328B21110941BC,
.iterated_1000_times = 0xF67397BCC966E6DF
},

{
.key = 0x0000200000000000,
.plain = 0x0000000000000000,
.cipher = 0x90BA680B22AEB525,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x9BCFFB98514CB6A6,
.iterated_1000_times = 0x727968AF8BEF52FD
},

{
.key = 0x0000100000000000,
.plain = 0x0000000000000000,
.cipher = 0xCE7A24F350E280B6,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x4BC0954F4B535598,
.iterated_1000_times = 0x4E234ADDF4122BDA
},

{
.key = 0x0000080000000000,
.plain = 0x0000000000000000,
.cipher = 0x882BFF0AA01A0B87,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x96B0B8C60D11C9CF,
.iterated_1000_times = 0x9289CC8834F34C4F
},

{
.key = 0x0000040000000000,
.plain = 0x0000000000000000,
.cipher = 0x25610288924511C2,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x5E0F10609C9F8FD8,
.iterated_1000_times = 0x6A0EF0F876ACA153
},

{
.key = 0x0000020000000000,
.plain = 0x0000000000000000,
.cipher = 0xC71516C29C75D170,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x6103866AB65CFCAC,
.iterated_1000_times = 0x47A58CC7E3BEE809
},

{
.key = 0x0000010000000000,
.plain = 0x0000000000000000,
.cipher = 0x8CA64DE9C1B123A7,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x0000000000000000,
.iterated_1000_times = 0x0000000000000000
},

{
.key = 0x0000008000000000,
.plain = 0x0000000000000000,
.cipher = 0x5199C29A52C9F059,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x30F72222BDE34AFA,
.iterated_1000_times = 0x7BF7933841FFC21F
},

{
.key = 0x0000004000000000,
.plain = 0x0000000000000000,
.cipher = 0xC22F0A294A71F29F,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x72CE2A0D94EBD9D6,
.iterated_1000_times = 0xAE674E8993690593
},

{
.key = 0x0000002000000000,
.plain = 0x0000000000000000,
.cipher = 0xEE371483714C02EA,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x0BCAE5EBB65B0D89,
.iterated_1000_times = 0xE50314779BB752B8
},

{
.key = 0x0000001000000000,
.plain = 0x0000000000000000,
.cipher = 0xA81FBD448F9E522F,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0xC29BF0411F9FB1FF,
.iterated_1000_times = 0x3A7956A60F0D3870
},

{
.key = 0x0000000800000000,
.plain = 0x0000000000000000,
.cipher = 0x4F644C92E192DFED,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x8179CEDCF9747E20,
.iterated_1000_times = 0x02B15BDF54EFC971
},

{
.key = 0x0000000400000000,
.plain = 0x0000000000000000,
.cipher = 0x1AFA9A66A6DF92AE,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x55E55F1C8360A9C8,
.iterated_1000_times = 0xFA2DF6016FB97F6B
},

{
.key = 0x0000000200000000,
.plain = 0x0000000000000000,
.cipher = 0xB3C1CC715CB879D8,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x7AF4FF1DD1C6DCB6,
.iterated_1000_times = 0xA40E0A841437BC1F
},

{
.key = 0x0000000100000000,
.plain = 0x0000000000000000,
.cipher = 0x8CA64DE9C1B123A7,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x0000000000000000,
.iterated_1000_times = 0x0000000000000000
},

{
.key = 0x0000000080000000,
.plain = 0x0000000000000000,
.cipher = 0x19D032E64AB0BD8B,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x65F1F8A4BC3DA5B7,
.iterated_1000_times = 0x9A4928B72076A579
},

{
.key = 0x0000000040000000,
.plain = 0x0000000000000000,
.cipher = 0x3CFAA7A7DC8720DC,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x418883502E606905,
.iterated_1000_times = 0x0CAECC8814864F05
},

{
.key = 0x0000000020000000,
.plain = 0x0000000000000000,
.cipher = 0xB7265F7F447AC6F3,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x17A6FDC0827E427A,
.iterated_1000_times = 0x7B22AE8457C37D3A
},

{
.key = 0x0000000010000000,
.plain = 0x0000000000000000,
.cipher = 0x9DB73B3C0D163F54,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x03FDCA66095EFB4A,
.iterated_1000_times = 0xF856FF043BCCF2C3
},

{
.key = 0x0000000008000000,
.plain = 0x0000000000000000,
.cipher = 0x8181B65BABF4A975,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x733C14A3503555E1,
.iterated_1000_times = 0x7472E191346264F3
},

{
.key = 0x0000000004000000,
.plain = 0x0000000000000000,
.cipher = 0x93C9B64042EAA240,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x3429B46392177D73,
.iterated_1000_times = 0x7D71912081998047
},

{
.key = 0x0000000002000000,
.plain = 0x0000000000000000,
.cipher = 0x5570530829705592,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x399B7400B0F18B6E,
.iterated_1000_times = 0xF3B76BAC729C96A2
},

{
.key = 0x0000000001000000,
.plain = 0x0000000000000000,
.cipher = 0x8CA64DE9C1B123A7,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x0000000000000000,
.iterated_1000_times = 0x0000000000000000
},

{
.key = 0x0000000000800000,
.plain = 0x0000000000000000,
.cipher = 0x8638809E878787A0,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x9DAF9D5B8F881E6D,
.iterated_1000_times = 0x59C63C6CE254A415
},

{
.key = 0x0000000000400000,
.plain = 0x0000000000000000,
.cipher = 0x41B9A79AF79AC208,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x3093349F22C1D915,
.iterated_1000_times = 0x57A373A06C2B824E
},

{
.key = 0x0000000000200000,
.plain = 0x0000000000000000,
.cipher = 0x7A9BE42F2009A892,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x979D68265D0444BF,
.iterated_1000_times = 0x08951924006F2275
},

{
.key = 0x0000000000100000,
.plain = 0x0000000000000000,
.cipher = 0x29038D56BA6D2745,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x2502186BE1E6227E,
.iterated_1000_times = 0x42C30EB4AA62D0C5
},

{
.key = 0x0000000000080000,
.plain = 0x0000000000000000,
.cipher = 0x5495C6ABF1E5DF51,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x5D098A0B0F96B856,
.iterated_1000_times = 0xBA7ECC30012C1485
},

{
.key = 0x0000000000040000,
.plain = 0x0000000000000000,
.cipher = 0xAE13DBD561488933,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0xDF591EF05C4A31CC,
.iterated_1000_times = 0xF3EC672B2A45F7DC
},

{
.key = 0x0000000000020000,
.plain = 0x0000000000000000,
.cipher = 0x024D1FFA8904E389,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0xF775ED6299B76BA2,
.iterated_1000_times = 0xE0F70281F7185E9B
},

{
.key = 0x0000000000010000,
.plain = 0x0000000000000000,
.cipher = 0x8CA64DE9C1B123A7,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x0000000000000000,
.iterated_1000_times = 0x0000000000000000
},

{
.key = 0x0000000000008000,
.plain = 0x0000000000000000,
.cipher = 0xD1399712F99BF02E,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0xE62D98EB4E760474,
.iterated_1000_times = 0xAA4CF8BE8AAE16F3
},

{
.key = 0x0000000000004000,
.plain = 0x0000000000000000,
.cipher = 0x14C1D7C1CFFEC79E,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0xFC592EFDB0299379,
.iterated_1000_times = 0x611C65187BEEB354
},

{
.key = 0x0000000000002000,
.plain = 0x0000000000000000,
.cipher = 0x1DE5279DAE3BED6F,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0xD02A61ECB45A8E86,
.iterated_1000_times = 0xCD161A355055F9EC
},

{
.key = 0x0000000000001000,
.plain = 0x0000000000000000,
.cipher = 0xE941A33F85501303,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0xAC7BA601AA1DFBB4,
.iterated_1000_times = 0x08B0ECF58BA2F737
},

{
.key = 0x0000000000000800,
.plain = 0x0000000000000000,
.cipher = 0xDA99DBBC9A03F379,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x8CA9ADB9AB5F9E22,
.iterated_1000_times = 0x6BD06DD1AC2DB53F
},

{
.key = 0x0000000000000400,
.plain = 0x0000000000000000,
.cipher = 0xB7FC92F91D8E92E9,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x0A46AEFEA0586C99,
.iterated_1000_times = 0x4D279FC5E7775E3C
},

{
.key = 0x0000000000000200,
.plain = 0x0000000000000000,
.cipher = 0xAE8E5CAA3CA04E85,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x29455C0AB803FEBC,
.iterated_1000_times = 0x25E3A6CB1EEA5103
},

{
.key = 0x0000000000000100,
.plain = 0x0000000000000000,
.cipher = 0x8CA64DE9C1B123A7,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x0000000000000000,
.iterated_1000_times = 0x0000000000000000
},

{
.key = 0x0000000000000080,
.plain = 0x0000000000000000,
.cipher = 0x9CC62DF43B6EED74,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x70D81B693DE59BFE,
.iterated_1000_times = 0xC0691B4F4C6FD5D4
},

{
.key = 0x0000000000000040,
.plain = 0x0000000000000000,
.cipher = 0xD863DBB5C59A91A0,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x9E8FC8F352C5A827,
.iterated_1000_times = 0x939032E8CC65BDA6
},

{
.key = 0x0000000000000020,
.plain = 0x0000000000000000,
.cipher = 0xA1AB2190545B91D7,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x11E55B3845D4D37E,
.iterated_1000_times = 0xD0AE7310EFBB4423
},

{
.key = 0x0000000000000010,
.plain = 0x0000000000000000,
.cipher = 0x0875041E64C570F7,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0xB8E98D072C0EC3B0,
.iterated_1000_times = 0x1C2529CFA50BEEF5
},

{
.key = 0x0000000000000008,
.plain = 0x0000000000000000,
.cipher = 0x5A594528BEBEF1CC,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x4591DEF0F1BCA860,
.iterated_1000_times = 0xEB7F094DCCA72284
},

{
.key = 0x0000000000000004,
.plain = 0x0000000000000000,
.cipher = 0xFCDB3291DE21F0C0,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x9B2F3C7C4CC05F30,
.iterated_1000_times = 0xA2628423B0719F91
},

{
.key = 0x0000000000000002,
.plain = 0x0000000000000000,
.cipher = 0x869EFD7F9F265A09,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x2812AC2768B3750E,
.iterated_1000_times = 0xDADBDABB5C5BA665
},

{
.key = 0x0000000000000001,
.plain = 0x0000000000000000,
.cipher = 0x8CA64DE9C1B123A7,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x0000000000000000,
.iterated_1000_times = 0x0000000000000000
},

//Test vectors -- set 2
//==================== =

{
.key = 0x0000000000000000,
.plain = 0x8000000000000000,
.cipher = 0x95F8A5E5DD31D900,
.decrypted = 0x8000000000000000,
.iterated_100_times = 0x8000000000000000,
.iterated_1000_times = 0x8000000000000000
},

{
.key = 0x0000000000000000,
.plain = 0x4000000000000000,
.cipher = 0xDD7F121CA5015619,
.decrypted = 0x4000000000000000,
.iterated_100_times = 0x4000000000000000,
.iterated_1000_times = 0x4000000000000000
},

{
.key = 0x0000000000000000,
.plain = 0x2000000000000000,
.cipher = 0x2E8653104F3834EA,
.decrypted = 0x2000000000000000,
.iterated_100_times = 0x2000000000000000,
.iterated_1000_times = 0x2000000000000000
},

{
.key = 0x0000000000000000,
.plain = 0x1000000000000000,
.cipher = 0x4BD388FF6CD81D4F,
.decrypted = 0x1000000000000000,
.iterated_100_times = 0x1000000000000000,
.iterated_1000_times = 0x1000000000000000
},

{
.key = 0x0000000000000000,
.plain = 0x0800000000000000,
.cipher = 0x20B9E767B2FB1456,
.decrypted = 0x0800000000000000,
.iterated_100_times = 0x0800000000000000,
.iterated_1000_times = 0x0800000000000000
},

{
.key = 0x0000000000000000,
.plain = 0x0400000000000000,
.cipher = 0x55579380D77138EF,
.decrypted = 0x0400000000000000,
.iterated_100_times = 0x0400000000000000,
.iterated_1000_times = 0x0400000000000000
},

{
.key = 0x0000000000000000,
.plain = 0x0200000000000000,
.cipher = 0x6CC5DEFAAF04512F,
.decrypted = 0x0200000000000000,
.iterated_100_times = 0x0200000000000000,
.iterated_1000_times = 0x0200000000000000
},

{
.key = 0x0000000000000000,
.plain = 0x0100000000000000,
.cipher = 0x0D9F279BA5D87260,
.decrypted = 0x0100000000000000,
.iterated_100_times = 0x0100000000000000,
.iterated_1000_times = 0x0100000000000000
},

{
.key = 0x0000000000000000,
.plain = 0x0080000000000000,
.cipher = 0xD9031B0271BD5A0A,
.decrypted = 0x0080000000000000,
.iterated_100_times = 0x0080000000000000,
.iterated_1000_times = 0x0080000000000000
},

{
.key = 0x0000000000000000,
.plain = 0x0040000000000000,
.cipher = 0x424250B37C3DD951,
.decrypted = 0x0040000000000000,
.iterated_100_times = 0x0040000000000000,
.iterated_1000_times = 0x0040000000000000
},

{
.key = 0x0000000000000000,
.plain = 0x0020000000000000,
.cipher = 0xB8061B7ECD9A21E5,
.decrypted = 0x0020000000000000,
.iterated_100_times = 0x0020000000000000,
.iterated_1000_times = 0x0020000000000000
},

{
.key = 0x0000000000000000,
.plain = 0x0010000000000000,
.cipher = 0xF15D0F286B65BD28,
.decrypted = 0x0010000000000000,
.iterated_100_times = 0x0010000000000000,
.iterated_1000_times = 0x0010000000000000
},

{
.key = 0x0000000000000000,
.plain = 0x0008000000000000,
.cipher = 0xADD0CC8D6E5DEBA1,
.decrypted = 0x0008000000000000,
.iterated_100_times = 0x0008000000000000,
.iterated_1000_times = 0x0008000000000000
},

{
.key = 0x0000000000000000,
.plain = 0x0004000000000000,
.cipher = 0xE6D5F82752AD63D1,
.decrypted = 0x0004000000000000,
.iterated_100_times = 0x0004000000000000,
.iterated_1000_times = 0x0004000000000000
},

{
.key = 0x0000000000000000,
.plain = 0x0002000000000000,
.cipher = 0xECBFE3BD3F591A5E,
.decrypted = 0x0002000000000000,
.iterated_100_times = 0x0002000000000000,
.iterated_1000_times = 0x0002000000000000
},

{
.key = 0x0000000000000000,
.plain = 0x0001000000000000,
.cipher = 0xF356834379D165CD,
.decrypted = 0x0001000000000000,
.iterated_100_times = 0x0001000000000000,
.iterated_1000_times = 0x0001000000000000
},

{
.key = 0x0000000000000000,
.plain = 0x0000800000000000,
.cipher = 0x2B9F982F20037FA9,
.decrypted = 0x0000800000000000,
.iterated_100_times = 0x0000800000000000,
.iterated_1000_times = 0x0000800000000000
},

{
.key = 0x0000000000000000,
.plain = 0x0000400000000000,
.cipher = 0x889DE068A16F0BE6,
.decrypted = 0x0000400000000000,
.iterated_100_times = 0x0000400000000000,
.iterated_1000_times = 0x0000400000000000
},

{
.key = 0x0000000000000000,
.plain = 0x0000200000000000,
.cipher = 0xE19E275D846A1298,
.decrypted = 0x0000200000000000,
.iterated_100_times = 0x0000200000000000,
.iterated_1000_times = 0x0000200000000000
},

{
.key = 0x0000000000000000,
.plain = 0x0000100000000000,
.cipher = 0x329A8ED523D71AEC,
.decrypted = 0x0000100000000000,
.iterated_100_times = 0x0000100000000000,
.iterated_1000_times = 0x0000100000000000
},

{
.key = 0x0000000000000000,
.plain = 0x0000080000000000,
.cipher = 0xE7FCE22557D23C97,
.decrypted = 0x0000080000000000,
.iterated_100_times = 0x0000080000000000,
.iterated_1000_times = 0x0000080000000000
},

{
.key = 0x0000000000000000,
.plain = 0x0000040000000000,
.cipher = 0x12A9F5817FF2D65D,
.decrypted = 0x0000040000000000,
.iterated_100_times = 0x0000040000000000,
.iterated_1000_times = 0x0000040000000000
},

{
.key = 0x0000000000000000,
.plain = 0x0000020000000000,
.cipher = 0xA484C3AD38DC9C19,
.decrypted = 0x0000020000000000,
.iterated_100_times = 0x0000020000000000,
.iterated_1000_times = 0x0000020000000000
},

{
.key = 0x0000000000000000,
.plain = 0x0000010000000000,
.cipher = 0xFBE00A8A1EF8AD72,
.decrypted = 0x0000010000000000,
.iterated_100_times = 0x0000010000000000,
.iterated_1000_times = 0x0000010000000000
},

{
.key = 0x0000000000000000,
.plain = 0x0000008000000000,
.cipher = 0x750D079407521363,
.decrypted = 0x0000008000000000,
.iterated_100_times = 0x0000008000000000,
.iterated_1000_times = 0x0000008000000000
},

{
.key = 0x0000000000000000,
.plain = 0x0000004000000000,
.cipher = 0x64FEED9C724C2FAF,
.decrypted = 0x0000004000000000,
.iterated_100_times = 0x0000004000000000,
.iterated_1000_times = 0x0000004000000000
},

{
.key = 0x0000000000000000,
.plain = 0x0000002000000000,
.cipher = 0xF02B263B328E2B60,
.decrypted = 0x0000002000000000,
.iterated_100_times = 0x0000002000000000,
.iterated_1000_times = 0x0000002000000000
},

{
.key = 0x0000000000000000,
.plain = 0x0000001000000000,
.cipher = 0x9D64555A9A10B852,
.decrypted = 0x0000001000000000,
.iterated_100_times = 0x0000001000000000,
.iterated_1000_times = 0x0000001000000000
},

{
.key = 0x0000000000000000,
.plain = 0x0000000800000000,
.cipher = 0xD106FF0BED5255D7,
.decrypted = 0x0000000800000000,
.iterated_100_times = 0x0000000800000000,
.iterated_1000_times = 0x0000000800000000
},

{
.key = 0x0000000000000000,
.plain = 0x0000000400000000,
.cipher = 0xE1652C6B138C64A5,
.decrypted = 0x0000000400000000,
.iterated_100_times = 0x0000000400000000,
.iterated_1000_times = 0x0000000400000000
},

{
.key = 0x0000000000000000,
.plain = 0x0000000200000000,
.cipher = 0xE428581186EC8F46,
.decrypted = 0x0000000200000000,
.iterated_100_times = 0x0000000200000000,
.iterated_1000_times = 0x0000000200000000
},

{
.key = 0x0000000000000000,
.plain = 0x0000000100000000,
.cipher = 0xAEB5F5EDE22D1A36,
.decrypted = 0x0000000100000000,
.iterated_100_times = 0x0000000100000000,
.iterated_1000_times = 0x0000000100000000
},

{
.key = 0x0000000000000000,
.plain = 0x0000000080000000,
.cipher = 0xE943D7568AEC0C5C,
.decrypted = 0x0000000080000000,
.iterated_100_times = 0x0000000080000000,
.iterated_1000_times = 0x0000000080000000
},

{
.key = 0x0000000000000000,
.plain = 0x0000000040000000,
.cipher = 0xDF98C8276F54B04B,
.decrypted = 0x0000000040000000,
.iterated_100_times = 0x0000000040000000,
.iterated_1000_times = 0x0000000040000000
},

{
.key = 0x0000000000000000,
.plain = 0x0000000020000000,
.cipher = 0xB160E4680F6C696F,
.decrypted = 0x0000000020000000,
.iterated_100_times = 0x0000000020000000,
.iterated_1000_times = 0x0000000020000000
},

{
.key = 0x0000000000000000,
.plain = 0x0000000010000000,
.cipher = 0xFA0752B07D9C4AB8,
.decrypted = 0x0000000010000000,
.iterated_100_times = 0x0000000010000000,
.iterated_1000_times = 0x0000000010000000
},

{
.key = 0x0000000000000000,
.plain = 0x0000000008000000,
.cipher = 0xCA3A2B036DBC8502,
.decrypted = 0x0000000008000000,
.iterated_100_times = 0x0000000008000000,
.iterated_1000_times = 0x0000000008000000
},

{
.key = 0x0000000000000000,
.plain = 0x0000000004000000,
.cipher = 0x5E0905517BB59BCF,
.decrypted = 0x0000000004000000,
.iterated_100_times = 0x0000000004000000,
.iterated_1000_times = 0x0000000004000000
},

{
.key = 0x0000000000000000,
.plain = 0x0000000002000000,
.cipher = 0x814EEB3B91D90726,
.decrypted = 0x0000000002000000,
.iterated_100_times = 0x0000000002000000,
.iterated_1000_times = 0x0000000002000000
},

{
.key = 0x0000000000000000,
.plain = 0x0000000001000000,
.cipher = 0x4D49DB1532919C9F,
.decrypted = 0x0000000001000000,
.iterated_100_times = 0x0000000001000000,
.iterated_1000_times = 0x0000000001000000
},

{
.key = 0x0000000000000000,
.plain = 0x0000000000800000,
.cipher = 0x25EB5FC3F8CF0621,
.decrypted = 0x0000000000800000,
.iterated_100_times = 0x0000000000800000,
.iterated_1000_times = 0x0000000000800000
},

{
.key = 0x0000000000000000,
.plain = 0x0000000000400000,
.cipher = 0xAB6A20C0620D1C6F,
.decrypted = 0x0000000000400000,
.iterated_100_times = 0x0000000000400000,
.iterated_1000_times = 0x0000000000400000
},

{
.key = 0x0000000000000000,
.plain = 0x0000000000200000,
.cipher = 0x79E90DBC98F92CCA,
.decrypted = 0x0000000000200000,
.iterated_100_times = 0x0000000000200000,
.iterated_1000_times = 0x0000000000200000
},

{
.key = 0x0000000000000000,
.plain = 0x0000000000100000,
.cipher = 0x866ECEDD8072BB0E,
.decrypted = 0x0000000000100000,
.iterated_100_times = 0x0000000000100000,
.iterated_1000_times = 0x0000000000100000
},

{
.key = 0x0000000000000000,
.plain = 0x0000000000080000,
.cipher = 0x8B54536F2F3E64A8,
.decrypted = 0x0000000000080000,
.iterated_100_times = 0x0000000000080000,
.iterated_1000_times = 0x0000000000080000
},

{
.key = 0x0000000000000000,
.plain = 0x0000000000040000,
.cipher = 0xEA51D3975595B86B,
.decrypted = 0x0000000000040000,
.iterated_100_times = 0x0000000000040000,
.iterated_1000_times = 0x0000000000040000
},

{
.key = 0x0000000000000000,
.plain = 0x0000000000020000,
.cipher = 0xCAFFC6AC4542DE31,
.decrypted = 0x0000000000020000,
.iterated_100_times = 0x0000000000020000,
.iterated_1000_times = 0x0000000000020000
},

{
.key = 0x0000000000000000,
.plain = 0x0000000000010000,
.cipher = 0x8DD45A2DDF90796C,
.decrypted = 0x0000000000010000,
.iterated_100_times = 0x0000000000010000,
.iterated_1000_times = 0x0000000000010000
},

{
.key = 0x0000000000000000,
.plain = 0x0000000000008000,
.cipher = 0x1029D55E880EC2D0,
.decrypted = 0x0000000000008000,
.iterated_100_times = 0x0000000000008000,
.iterated_1000_times = 0x0000000000008000
},

{
.key = 0x0000000000000000,
.plain = 0x0000000000004000,
.cipher = 0x5D86CB23639DBEA9,
.decrypted = 0x0000000000004000,
.iterated_100_times = 0x0000000000004000,
.iterated_1000_times = 0x0000000000004000
},

{
.key = 0x0000000000000000,
.plain = 0x0000000000002000,
.cipher = 0x1D1CA853AE7C0C5F,
.decrypted = 0x0000000000002000,
.iterated_100_times = 0x0000000000002000,
.iterated_1000_times = 0x0000000000002000
},

{
.key = 0x0000000000000000,
.plain = 0x0000000000001000,
.cipher = 0xCE332329248F3228,
.decrypted = 0x0000000000001000,
.iterated_100_times = 0x0000000000001000,
.iterated_1000_times = 0x0000000000001000
},

{
.key = 0x0000000000000000,
.plain = 0x0000000000000800,
.cipher = 0x8405D1ABE24FB942,
.decrypted = 0x0000000000000800,
.iterated_100_times = 0x0000000000000800,
.iterated_1000_times = 0x0000000000000800
},

{
.key = 0x0000000000000000,
.plain = 0x0000000000000400,
.cipher = 0xE643D78090CA4207,
.decrypted = 0x0000000000000400,
.iterated_100_times = 0x0000000000000400,
.iterated_1000_times = 0x0000000000000400
},

{
.key = 0x0000000000000000,
.plain = 0x0000000000000200,
.cipher = 0x48221B9937748A23,
.decrypted = 0x0000000000000200,
.iterated_100_times = 0x0000000000000200,
.iterated_1000_times = 0x0000000000000200
},

{
.key = 0x0000000000000000,
.plain = 0x0000000000000100,
.cipher = 0xDD7C0BBD61FAFD54,
.decrypted = 0x0000000000000100,
.iterated_100_times = 0x0000000000000100,
.iterated_1000_times = 0x0000000000000100
},

{
.key = 0x0000000000000000,
.plain = 0x0000000000000080,
.cipher = 0x2FBC291A570DB5C4,
.decrypted = 0x0000000000000080,
.iterated_100_times = 0x0000000000000080,
.iterated_1000_times = 0x0000000000000080
},

{
.key = 0x0000000000000000,
.plain = 0x0000000000000040,
.cipher = 0xE07C30D7E4E26E12,
.decrypted = 0x0000000000000040,
.iterated_100_times = 0x0000000000000040,
.iterated_1000_times = 0x0000000000000040
},

{
.key = 0x0000000000000000,
.plain = 0x0000000000000020,
.cipher = 0x0953E2258E8E90A1,
.decrypted = 0x0000000000000020,
.iterated_100_times = 0x0000000000000020,
.iterated_1000_times = 0x0000000000000020
},

{
.key = 0x0000000000000000,
.plain = 0x0000000000000010,
.cipher = 0x5B711BC4CEEBF2EE,
.decrypted = 0x0000000000000010,
.iterated_100_times = 0x0000000000000010,
.iterated_1000_times = 0x0000000000000010
},

{
.key = 0x0000000000000000,
.plain = 0x0000000000000008,
.cipher = 0xCC083F1E6D9E85F6,
.decrypted = 0x0000000000000008,
.iterated_100_times = 0x0000000000000008,
.iterated_1000_times = 0x0000000000000008
},

{
.key = 0x0000000000000000,
.plain = 0x0000000000000004,
.cipher = 0xD2FD8867D50D2DFE,
.decrypted = 0x0000000000000004,
.iterated_100_times = 0x0000000000000004,
.iterated_1000_times = 0x0000000000000004
},

{
.key = 0x0000000000000000,
.plain = 0x0000000000000002,
.cipher = 0x06E7EA22CE92708F,
.decrypted = 0x0000000000000002,
.iterated_100_times = 0x0000000000000002,
.iterated_1000_times = 0x0000000000000002
},

{
.key = 0x0000000000000000,
.plain = 0x0000000000000001,
.cipher = 0x166B40B44ABA4BD6,
.decrypted = 0x0000000000000001,
.iterated_100_times = 0x0000000000000001,
.iterated_1000_times = 0x0000000000000001
},

//Test vectors -- set 3
//==================== =

{
.key = 0x0000000000000000,
.plain = 0x0000000000000000,
.cipher = 0x8CA64DE9C1B123A7,
.decrypted = 0x0000000000000000,
.iterated_100_times = 0x0000000000000000,
.iterated_1000_times = 0x0000000000000000
},

{
.key = 0x0101010101010101,
.plain = 0x0101010101010101,
.cipher = 0x994D4DC157B96C52,
.decrypted = 0x0101010101010101,
.iterated_100_times = 0x0101010101010101,
.iterated_1000_times = 0x0101010101010101
},

{
.key = 0x0202020202020202,
.plain = 0x0202020202020202,
.cipher = 0xE127C2B61D98E6E2,
.decrypted = 0x0202020202020202,
.iterated_100_times = 0xB575F7E036BBDE72,
.iterated_1000_times = 0xEF66EB1095238FBB
},

{
.key = 0x0303030303030303,
.plain = 0x0303030303030303,
.cipher = 0x984C91D78A269CE3,
.decrypted = 0x0303030303030303,
.iterated_100_times = 0xF46D7FEC491D049B,
.iterated_1000_times = 0x1B54D2349C80B4F2
},

{
.key = 0x0404040404040404,
.plain = 0x0404040404040404,
.cipher = 0x1F4570BB77550683,
.decrypted = 0x0404040404040404,
.iterated_100_times = 0xC95FC0A6EF6E8ED6,
.iterated_1000_times = 0x373ADDEBEBA0E681
},

{
.key = 0x0505050505050505,
.plain = 0x0505050505050505,
.cipher = 0x3990ABF98D672B16,
.decrypted = 0x0505050505050505,
.iterated_100_times = 0xFE4AA77EFE851A58,
.iterated_1000_times = 0x434D8AC87CAF59AF
},

{
.key = 0x0606060606060606,
.plain = 0x0606060606060606,
.cipher = 0x3F5150BBA081D585,
.decrypted = 0x0606060606060606,
.iterated_100_times = 0xD1C5600E7B186BB1,
.iterated_1000_times = 0x275229B5D2536536
},

{
.key = 0x0707070707070707,
.plain = 0x0707070707070707,
.cipher = 0xC65242248C9CF6F2,
.decrypted = 0x0707070707070707,
.iterated_100_times = 0xDE3A1731A1D3324B,
.iterated_1000_times = 0xC9BC25D7BD6E4D43
},

{
.key = 0x0808080808080808,
.plain = 0x0808080808080808,
.cipher = 0x10772D40FAD24257,
.decrypted = 0x0808080808080808,
.iterated_100_times = 0xDB3214AD3B35C572,
.iterated_1000_times = 0x4E8A406CA4FEBC52
},

{
.key = 0x0909090909090909,
.plain = 0x0909090909090909,
.cipher = 0xF0139440647A6E7B,
.decrypted = 0x0909090909090909,
.iterated_100_times = 0xBD34ED357BC3938B,
.iterated_1000_times = 0x3944A4F231239FC9
},

{
.key = 0x0A0A0A0A0A0A0A0A,
.plain = 0x0A0A0A0A0A0A0A0A,
.cipher = 0x0A288603044D740C,
.decrypted = 0x0A0A0A0A0A0A0A0A,
.iterated_100_times = 0xC4CB008E3A0A62A9,
.iterated_1000_times = 0xBF8FB60063D373AE
},

{
.key = 0x0B0B0B0B0B0B0B0B,
.plain = 0x0B0B0B0B0B0B0B0B,
.cipher = 0x6359916942F7438F,
.decrypted = 0x0B0B0B0B0B0B0B0B,
.iterated_100_times = 0x74F7B3F057E53E49,
.iterated_1000_times = 0xDDCCFBDA8C53A472
},

{
.key = 0x0C0C0C0C0C0C0C0C,
.plain = 0x0C0C0C0C0C0C0C0C,
.cipher = 0x934316AE443CF08B,
.decrypted = 0x0C0C0C0C0C0C0C0C,
.iterated_100_times = 0xED62660F284343CD,
.iterated_1000_times = 0x3DB428FE2867D620
},

{
.key = 0x0D0D0D0D0D0D0D0D,
.plain = 0x0D0D0D0D0D0D0D0D,
.cipher = 0xE3F56D7F1130A2B7,
.decrypted = 0x0D0D0D0D0D0D0D0D,
.iterated_100_times = 0x70EC69AF05EC4476,
.iterated_1000_times = 0x64F1F4B38665C7ED
},

{
.key = 0x0E0E0E0E0E0E0E0E,
.plain = 0x0E0E0E0E0E0E0E0E,
.cipher = 0xA2E4705087C6B6B4,
.decrypted = 0x0E0E0E0E0E0E0E0E,
.iterated_100_times = 0x08006AE1A9F8798B,
.iterated_1000_times = 0x2F8DBD285D5353C7
},

{
.key = 0x0F0F0F0F0F0F0F0F,
.plain = 0x0F0F0F0F0F0F0F0F,
.cipher = 0xD5D76E09A447E8C3,
.decrypted = 0x0F0F0F0F0F0F0F0F,
.iterated_100_times = 0x2804106DB462431F,
.iterated_1000_times = 0x2614F4610CF0A42F
},

{
.key = 0x1010101010101010,
.plain = 0x1010101010101010,
.cipher = 0xDD7515F2BFC17F85,
.decrypted = 0x1010101010101010,
.iterated_100_times = 0x59E4B20A2B9E13A4,
.iterated_1000_times = 0x532E34B260E171B8
},

{
.key = 0x1111111111111111,
.plain = 0x1111111111111111,
.cipher = 0xF40379AB9E0EC533,
.decrypted = 0x1111111111111111,
.iterated_100_times = 0x78A1257D2332D471,
.iterated_1000_times = 0x3D9D7B0A4E0E3576
},

{
.key = 0x1212121212121212,
.plain = 0x1212121212121212,
.cipher = 0x96CD27784D1563E5,
.decrypted = 0x1212121212121212,
.iterated_100_times = 0xA7712A48A287D855,
.iterated_1000_times = 0x365B0126EB87A873
},

{
.key = 0x1313131313131313,
.plain = 0x1313131313131313,
.cipher = 0x2911CF5E94D33FE1,
.decrypted = 0x1313131313131313,
.iterated_100_times = 0xB56D216335FBC5E9,
.iterated_1000_times = 0x8019AFAEF257D470
},

{
.key = 0x1414141414141414,
.plain = 0x1414141414141414,
.cipher = 0x377B7F7CA3E5BBB3,
.decrypted = 0x1414141414141414,
.iterated_100_times = 0xFA555D286B1156F2,
.iterated_1000_times = 0x4727FE29150A7F16
},

{
.key = 0x1515151515151515,
.plain = 0x1515151515151515,
.cipher = 0x701AA63832905A92,
.decrypted = 0x1515151515151515,
.iterated_100_times = 0x0675C352CB6B268C,
.iterated_1000_times = 0x11773ECEFE3411F3
},

{
.key = 0x1616161616161616,
.plain = 0x1616161616161616,
.cipher = 0x2006E716C4252D6D,
.decrypted = 0x1616161616161616,
.iterated_100_times = 0xF3714D29ACEDE2DC,
.iterated_1000_times = 0xF98398EA8B2AC1C2
},

{
.key = 0x1717171717171717,
.plain = 0x1717171717171717,
.cipher = 0x452C1197422469F8,
.decrypted = 0x1717171717171717,
.iterated_100_times = 0x207E4B61863A19A9,
.iterated_1000_times = 0x0E09BEBEA09D939F
},

{
.key = 0x1818181818181818,
.plain = 0x1818181818181818,
.cipher = 0xC33FD1EB49CB64DA,
.decrypted = 0x1818181818181818,
.iterated_100_times = 0x06D0D308437682BF,
.iterated_1000_times = 0x957391D4A8E6E210
},

{
.key = 0x1919191919191919,
.plain = 0x1919191919191919,
.cipher = 0x7572278F364EB50D,
.decrypted = 0x1919191919191919,
.iterated_100_times = 0x3BDA68891F411E27,
.iterated_1000_times = 0xADF735FD0804EBD2
},

{
.key = 0x1A1A1A1A1A1A1A1A,
.plain = 0x1A1A1A1A1A1A1A1A,
.cipher = 0x69E51488403EF4C3,
.decrypted = 0x1A1A1A1A1A1A1A1A,
.iterated_100_times = 0xB19C00E014F96E7B,
.iterated_1000_times = 0xDAE7603FB12C479E
},

{
.key = 0x1B1B1B1B1B1B1B1B,
.plain = 0x1B1B1B1B1B1B1B1B,
.cipher = 0xFF847E0ADF192825,
.decrypted = 0x1B1B1B1B1B1B1B1B,
.iterated_100_times = 0xCEF52AA0F6041207,
.iterated_1000_times = 0x450A50776FE1D52D
},

{
.key = 0x1C1C1C1C1C1C1C1C,
.plain = 0x1C1C1C1C1C1C1C1C,
.cipher = 0x521B7FB3B41BB791,
.decrypted = 0x1C1C1C1C1C1C1C1C,
.iterated_100_times = 0xF9115CB99EE29D17,
.iterated_1000_times = 0x4306B2FAC11DD0D5
},

{
.key = 0x1D1D1D1D1D1D1D1D,
.plain = 0x1D1D1D1D1D1D1D1D,
.cipher = 0x26059A6A0F3F6B35,
.decrypted = 0x1D1D1D1D1D1D1D1D,
.iterated_100_times = 0xF83B8693D0A61969,
.iterated_1000_times = 0x9313A53C6051BDB3
},

{
.key = 0x1E1E1E1E1E1E1E1E,
.plain = 0x1E1E1E1E1E1E1E1E,
.cipher = 0xF24A8D2231C77538,
.decrypted = 0x1E1E1E1E1E1E1E1E,
.iterated_100_times = 0x5A4F39F8F17C06C7,
.iterated_1000_times = 0x53827EDCF52A6FDC
},

{
.key = 0x1F1F1F1F1F1F1F1F,
.plain = 0x1F1F1F1F1F1F1F1F,
.cipher = 0x4FD96EC0D3304EF6,
.decrypted = 0x1F1F1F1F1F1F1F1F,
.iterated_100_times = 0x148D2605CC9E58F7,
.iterated_1000_times = 0xBBFB81EE0E3EBE94
},

{
.key = 0x2020202020202020,
.plain = 0x2020202020202020,
.cipher = 0x18A9D580A900B699,
.decrypted = 0x2020202020202020,
.iterated_100_times = 0xDEE7754452402184,
.iterated_1000_times = 0xB8DD4D82B55F134B
},

{
.key = 0x2121212121212121,
.plain = 0x2121212121212121,
.cipher = 0x88586E1D755B9B5A,
.decrypted = 0x2121212121212121,
.iterated_100_times = 0x53D24793D7540BEF,
.iterated_1000_times = 0xE4E7306C87527A86
},

{
.key = 0x2222222222222222,
.plain = 0x2222222222222222,
.cipher = 0x0F8ADFFB11DC2784,
.decrypted = 0x2222222222222222,
.iterated_100_times = 0x07D5A975DFA30B40,
.iterated_1000_times = 0xC94BE627ADD4C1F4
},

{
.key = 0x2323232323232323,
.plain = 0x2323232323232323,
.cipher = 0x2F30446C8312404A,
.decrypted = 0x2323232323232323,
.iterated_100_times = 0x5FEFB92AF665633A,
.iterated_1000_times = 0x9165CECAD1563F6F
},

{
.key = 0x2424242424242424,
.plain = 0x2424242424242424,
.cipher = 0x0BA03D9E6C196511,
.decrypted = 0x2424242424242424,
.iterated_100_times = 0xAEF52947F908450A,
.iterated_1000_times = 0x2607FBF97EC24B5F
},

{
.key = 0x2525252525252525,
.plain = 0x2525252525252525,
.cipher = 0x3E55E997611E4B7D,
.decrypted = 0x2525252525252525,
.iterated_100_times = 0x1223E578868C1EF6,
.iterated_1000_times = 0xE7287D8FE0A4383E
},

{
.key = 0x2626262626262626,
.plain = 0x2626262626262626,
.cipher = 0xB2522FB5F158F0DF,
.decrypted = 0x2626262626262626,
.iterated_100_times = 0x0ABA5827280C32B8,
.iterated_1000_times = 0xA1B49DCD07B91030
},

{
.key = 0x2727272727272727,
.plain = 0x2727272727272727,
.cipher = 0x2109425935406AB8,
.decrypted = 0x2727272727272727,
.iterated_100_times = 0x06267445D6A2B26C,
.iterated_1000_times = 0x98F3E5792D5976B1
},

{
.key = 0x2828282828282828,
.plain = 0x2828282828282828,
.cipher = 0x11A16028F310FF16,
.decrypted = 0x2828282828282828,
.iterated_100_times = 0xC87E6AA7024AA25D,
.iterated_1000_times = 0xAB5D4716E4461939
},

{
.key = 0x2929292929292929,
.plain = 0x2929292929292929,
.cipher = 0x73F0C45F379FE67F,
.decrypted = 0x2929292929292929,
.iterated_100_times = 0xC6146414D7439A59,
.iterated_1000_times = 0x481411E80BA14CAC
},

{
.key = 0x2A2A2A2A2A2A2A2A,
.plain = 0x2A2A2A2A2A2A2A2A,
.cipher = 0xDCAD4338F7523816,
.decrypted = 0x2A2A2A2A2A2A2A2A,
.iterated_100_times = 0xE17F92BFECD0AB5D,
.iterated_1000_times = 0x803ABFDA91580AC1
},

{
.key = 0x2B2B2B2B2B2B2B2B,
.plain = 0x2B2B2B2B2B2B2B2B,
.cipher = 0xB81634C1CEAB298C,
.decrypted = 0x2B2B2B2B2B2B2B2B,
.iterated_100_times = 0x5DE00ED35CDC7428,
.iterated_1000_times = 0xDE19633E77F4DB1F
},

{
.key = 0x2C2C2C2C2C2C2C2C,
.plain = 0x2C2C2C2C2C2C2C2C,
.cipher = 0xDD2CCB29B6C4C349,
.decrypted = 0x2C2C2C2C2C2C2C2C,
.iterated_100_times = 0xD3B6F9A1BD8B6B15,
.iterated_1000_times = 0x1A847AE704BAE175
},

{
.key = 0x2D2D2D2D2D2D2D2D,
.plain = 0x2D2D2D2D2D2D2D2D,
.cipher = 0x7D07A77A2ABD50A7,
.decrypted = 0x2D2D2D2D2D2D2D2D,
.iterated_100_times = 0x2BBEE289FFF55C85,
.iterated_1000_times = 0x501C267C682280B5
},

{
.key = 0x2E2E2E2E2E2E2E2E,
.plain = 0x2E2E2E2E2E2E2E2E,
.cipher = 0x30C1B0C1FD91D371,
.decrypted = 0x2E2E2E2E2E2E2E2E,
.iterated_100_times = 0x51A76271AD0E3A5F,
.iterated_1000_times = 0xD3DFC683AB67D88B
},

{
.key = 0x2F2F2F2F2F2F2F2F,
.plain = 0x2F2F2F2F2F2F2F2F,
.cipher = 0xC4427B31AC61973B,
.decrypted = 0x2F2F2F2F2F2F2F2F,
.iterated_100_times = 0x5E95FF4A1B470C9D,
.iterated_1000_times = 0xF895F6404407A911
},

{
.key = 0x3030303030303030,
.plain = 0x3030303030303030,
.cipher = 0xF47BB46273B15EB5,
.decrypted = 0x3030303030303030,
.iterated_100_times = 0x76BF3C2C0D1C4BD0,
.iterated_1000_times = 0x3CBDCFABC1F321D7
},

{
.key = 0x3131313131313131,
.plain = 0x3131313131313131,
.cipher = 0x655EA628CF62585F,
.decrypted = 0x3131313131313131,
.iterated_100_times = 0xE1F5527AAA65DF2B,
.iterated_1000_times = 0x3F8E6EB07693959F
},

{
.key = 0x3232323232323232,
.plain = 0x3232323232323232,
.cipher = 0xAC978C247863388F,
.decrypted = 0x3232323232323232,
.iterated_100_times = 0x353E49075AC19356,
.iterated_1000_times = 0x74986B6B48A70B9B
},

{
.key = 0x3333333333333333,
.plain = 0x3333333333333333,
.cipher = 0x0432ED386F2DE328,
.decrypted = 0x3333333333333333,
.iterated_100_times = 0x8D6B18F726B5BD30,
.iterated_1000_times = 0xFDB76D63EF051ADD
},

{
.key = 0x3434343434343434,
.plain = 0x3434343434343434,
.cipher = 0xD254014CB986B3C2,
.decrypted = 0x3434343434343434,
.iterated_100_times = 0x085509B51C375B80,
.iterated_1000_times = 0x31E9566BB30E081E
},

{
.key = 0x3535353535353535,
.plain = 0x3535353535353535,
.cipher = 0xB256E34BEDB49801,
.decrypted = 0x3535353535353535,
.iterated_100_times = 0xE42078571072F66E,
.iterated_1000_times = 0xD6DACEDE04CA0A34
},

{
.key = 0x3636363636363636,
.plain = 0x3636363636363636,
.cipher = 0x37F8759EB77E7BFC,
.decrypted = 0x3636363636363636,
.iterated_100_times = 0xAFEC7EB983086E29,
.iterated_1000_times = 0x13DC451CC0899787
},

{
.key = 0x3737373737373737,
.plain = 0x3737373737373737,
.cipher = 0x5013CA4F62C9CEA0,
.decrypted = 0x3737373737373737,
.iterated_100_times = 0xC618B626D7F59D7E,
.iterated_1000_times = 0x2400481DFA1DBB2B
},

{
.key = 0x3838383838383838,
.plain = 0x3838383838383838,
.cipher = 0x8940F7B3EACA5939,
.decrypted = 0x3838383838383838,
.iterated_100_times = 0x50E8C2DEA98D747A,
.iterated_1000_times = 0xF48E40812BCEDECB
},

{
.key = 0x3939393939393939,
.plain = 0x3939393939393939,
.cipher = 0xE22B19A55086774B,
.decrypted = 0x3939393939393939,
.iterated_100_times = 0xD580DC51FE300229,
.iterated_1000_times = 0x9B062BA3FCBCFDA7
},

{
.key = 0x3A3A3A3A3A3A3A3A,
.plain = 0x3A3A3A3A3A3A3A3A,
.cipher = 0xB04A2AAC925ABB0B,
.decrypted = 0x3A3A3A3A3A3A3A3A,
.iterated_100_times = 0x5ED71B36898C8267,
.iterated_1000_times = 0x274E36B383DF6DC9
},

{
.key = 0x3B3B3B3B3B3B3B3B,
.plain = 0x3B3B3B3B3B3B3B3B,
.cipher = 0x8D250D58361597FC,
.decrypted = 0x3B3B3B3B3B3B3B3B,
.iterated_100_times = 0xBC6F4D8E8A214F7F,
.iterated_1000_times = 0xFB73E01779F65CC9
},

{
.key = 0x3C3C3C3C3C3C3C3C,
.plain = 0x3C3C3C3C3C3C3C3C,
.cipher = 0x51F0114FB6A6CD37,
.decrypted = 0x3C3C3C3C3C3C3C3C,
.iterated_100_times = 0x30F373AE7D7D79FB,
.iterated_1000_times = 0x0FB0B4E51CB476F4
},

{
.key = 0x3D3D3D3D3D3D3D3D,
.plain = 0x3D3D3D3D3D3D3D3D,
.cipher = 0x9D0BB4DB830ECB73,
.decrypted = 0x3D3D3D3D3D3D3D3D,
.iterated_100_times = 0xA1F3CEA4B3D9CC9A,
.iterated_1000_times = 0x1AEF567D7490EC78
},

{
.key = 0x3E3E3E3E3E3E3E3E,
.plain = 0x3E3E3E3E3E3E3E3E,
.cipher = 0xE96089D6368F3E1A,
.decrypted = 0x3E3E3E3E3E3E3E3E,
.iterated_100_times = 0x542B44C055BB9634,
.iterated_1000_times = 0x6E977FDBC5E79034
},

{
.key = 0x3F3F3F3F3F3F3F3F,
.plain = 0x3F3F3F3F3F3F3F3F,
.cipher = 0x5C4CA877A4E1E92D,
.decrypted = 0x3F3F3F3F3F3F3F3F,
.iterated_100_times = 0xA1A31BF7C8CAB9E0,
.iterated_1000_times = 0xF7E4B7B1E23510C1
},

{
.key = 0x4040404040404040,
.plain = 0x4040404040404040,
.cipher = 0x6D55DDBC8DEA95FF,
.decrypted = 0x4040404040404040,
.iterated_100_times = 0xB25D93C2AB05A407,
.iterated_1000_times = 0xE9B4FEB769DC5164
},

{
.key = 0x4141414141414141,
.plain = 0x4141414141414141,
.cipher = 0x19DF84AC95551003,
.decrypted = 0x4141414141414141,
.iterated_100_times = 0xF3B7B874D651B0C1,
.iterated_1000_times = 0xCEAD31BFB196EC40
},

{
.key = 0x4242424242424242,
.plain = 0x4242424242424242,
.cipher = 0x724E7332696D08A7,
.decrypted = 0x4242424242424242,
.iterated_100_times = 0x230408DE94AF4851,
.iterated_1000_times = 0x18833E5C5ED786D6
},

{
.key = 0x4343434343434343,
.plain = 0x4343434343434343,
.cipher = 0xB91810B8CDC58FE2,
.decrypted = 0x4343434343434343,
.iterated_100_times = 0x23A07A213051D1E8,
.iterated_1000_times = 0xC916B9FCDA721A6A
},

{
.key = 0x4444444444444444,
.plain = 0x4444444444444444,
.cipher = 0x06E23526EDCCD0C4,
.decrypted = 0x4444444444444444,
.iterated_100_times = 0xB618703EC9F61F9C,
.iterated_1000_times = 0x995DE7AB92F8F80E
},

{
.key = 0x4545454545454545,
.plain = 0x4545454545454545,
.cipher = 0xEF52491D5468D441,
.decrypted = 0x4545454545454545,
.iterated_100_times = 0xC1B909D856C5FFEC,
.iterated_1000_times = 0x6535B033E837EF13
},

{
.key = 0x4646464646464646,
.plain = 0x4646464646464646,
.cipher = 0x48019C59E39B90C5,
.decrypted = 0x4646464646464646,
.iterated_100_times = 0x2099304DE58AB09A,
.iterated_1000_times = 0xD3AA7DEEB598209F
},

{
.key = 0x4747474747474747,
.plain = 0x4747474747474747,
.cipher = 0x0544083FB902D8C0,
.decrypted = 0x4747474747474747,
.iterated_100_times = 0x78F4BF46C9C74AD1,
.iterated_1000_times = 0xD4E42FC7A708DD03
},

{
.key = 0x4848484848484848,
.plain = 0x4848484848484848,
.cipher = 0x63B15CADA668CE12,
.decrypted = 0x4848484848484848,
.iterated_100_times = 0x14361721CBE46E6D,
.iterated_1000_times = 0xC4C055F1AB2E1499
},

{
.key = 0x4949494949494949,
.plain = 0x4949494949494949,
.cipher = 0xEACC0C1264171071,
.decrypted = 0x4949494949494949,
.iterated_100_times = 0x13E767AD4E4B1953,
.iterated_1000_times = 0x7570779E94106132
},

{
.key = 0x4A4A4A4A4A4A4A4A,
.plain = 0x4A4A4A4A4A4A4A4A,
.cipher = 0x9D2B8C0AC605F274,
.decrypted = 0x4A4A4A4A4A4A4A4A,
.iterated_100_times = 0xE60E8AC0EFC62DB0,
.iterated_1000_times = 0x66676C8CBA146CC6
},

{
.key = 0x4B4B4B4B4B4B4B4B,
.plain = 0x4B4B4B4B4B4B4B4B,
.cipher = 0xC90F2F4C98A8FB2A,
.decrypted = 0x4B4B4B4B4B4B4B4B,
.iterated_100_times = 0xBA52C22AC74C50CD,
.iterated_1000_times = 0x197A6690469A3027
},

{
.key = 0x4C4C4C4C4C4C4C4C,
.plain = 0x4C4C4C4C4C4C4C4C,
.cipher = 0x03481B4828FD1D04,
.decrypted = 0x4C4C4C4C4C4C4C4C,
.iterated_100_times = 0x8CE5269DA1F0110E,
.iterated_1000_times = 0x19A581FD31EC8B62
},

{
.key = 0x4D4D4D4D4D4D4D4D,
.plain = 0x4D4D4D4D4D4D4D4D,
.cipher = 0xC78FC45A1DCEA2E2,
.decrypted = 0x4D4D4D4D4D4D4D4D,
.iterated_100_times = 0x773E66FD6C2E08A6,
.iterated_1000_times = 0xE8F7A9B6AC18C81F
},

{
.key = 0x4E4E4E4E4E4E4E4E,
.plain = 0x4E4E4E4E4E4E4E4E,
.cipher = 0xDB96D88C3460D801,
.decrypted = 0x4E4E4E4E4E4E4E4E,
.iterated_100_times = 0x7917869634D54BBB,
.iterated_1000_times = 0x16C6AE839E2774BC
},

{
.key = 0x4F4F4F4F4F4F4F4F,
.plain = 0x4F4F4F4F4F4F4F4F,
.cipher = 0x6C69E720F5105518,
.decrypted = 0x4F4F4F4F4F4F4F4F,
.iterated_100_times = 0x6EA272483DFF7B5C,
.iterated_1000_times = 0xF5B13670596DAF2F
},

{
.key = 0x5050505050505050,
.plain = 0x5050505050505050,
.cipher = 0x0D262E418BC893F3,
.decrypted = 0x5050505050505050,
.iterated_100_times = 0x416B6966D60870FB,
.iterated_1000_times = 0x08FF56D93754D6D0
},

{
.key = 0x5151515151515151,
.plain = 0x5151515151515151,
.cipher = 0x6AD84FD7848A0A5C,
.decrypted = 0x5151515151515151,
.iterated_100_times = 0x2B018AF9843D6D73,
.iterated_1000_times = 0x5826597362AAB623
},

{
.key = 0x5252525252525252,
.plain = 0x5252525252525252,
.cipher = 0xC365CB35B34B6114,
.decrypted = 0x5252525252525252,
.iterated_100_times = 0x70D6A1812318FA52,
.iterated_1000_times = 0x7323A5995C42FB69
},

{
.key = 0x5353535353535353,
.plain = 0x5353535353535353,
.cipher = 0x1155392E877F42A9,
.decrypted = 0x5353535353535353,
.iterated_100_times = 0xA7B55CCAA2E6553C,
.iterated_1000_times = 0x9C290E630C976E43
},

{
.key = 0x5454545454545454,
.plain = 0x5454545454545454,
.cipher = 0x531BE5F9405DA715,
.decrypted = 0x5454545454545454,
.iterated_100_times = 0xB3B5D3FEBDDA3981,
.iterated_1000_times = 0xB0D39C349104E27E
},

{
.key = 0x5555555555555555,
.plain = 0x5555555555555555,
.cipher = 0x3BCDD41E6165A5E8,
.decrypted = 0x5555555555555555,
.iterated_100_times = 0x186FEF7B7A7283A1,
.iterated_1000_times = 0xD83AB81A85A8046E
},

{
.key = 0x5656565656565656,
.plain = 0x5656565656565656,
.cipher = 0x2B1FF5610A19270C,
.decrypted = 0x5656565656565656,
.iterated_100_times = 0x50953DA8CED81BFB,
.iterated_1000_times = 0xF16D0717BEEC9DCF
},

{
.key = 0x5757575757575757,
.plain = 0x5757575757575757,
.cipher = 0xD90772CF3F047CFD,
.decrypted = 0x5757575757575757,
.iterated_100_times = 0xF03447F802AA1DD4,
.iterated_1000_times = 0xF0F8F7D232F0184E
},

{
.key = 0x5858585858585858,
.plain = 0x5858585858585858,
.cipher = 0x1BEA27FFB72457B7,
.decrypted = 0x5858585858585858,
.iterated_100_times = 0x8707BB9950390709,
.iterated_1000_times = 0x55DFD7E8CAC23EF4
},

{
.key = 0x5959595959595959,
.plain = 0x5959595959595959,
.cipher = 0x85C3E0C429F34C27,
.decrypted = 0x5959595959595959,
.iterated_100_times = 0x582111E687076FA8,
.iterated_1000_times = 0x276D78F9EAFB523F
},

{
.key = 0x5A5A5A5A5A5A5A5A,
.plain = 0x5A5A5A5A5A5A5A5A,
.cipher = 0xF9038021E37C7618,
.decrypted = 0x5A5A5A5A5A5A5A5A,
.iterated_100_times = 0x3EBAF74BCA504FDC,
.iterated_1000_times = 0x248C7EE503B0C31C
},

{
.key = 0x5B5B5B5B5B5B5B5B,
.plain = 0x5B5B5B5B5B5B5B5B,
.cipher = 0x35BC6FF838DBA32F,
.decrypted = 0x5B5B5B5B5B5B5B5B,
.iterated_100_times = 0x657C416FDD97CE7A,
.iterated_1000_times = 0xBDF93AEA60AF226A
},

{
.key = 0x5C5C5C5C5C5C5C5C,
.plain = 0x5C5C5C5C5C5C5C5C,
.cipher = 0x4927ACC8CE45ECE7,
.decrypted = 0x5C5C5C5C5C5C5C5C,
.iterated_100_times = 0xA22D60CC973E4E08,
.iterated_1000_times = 0x48F5C04736EF8365
},

{
.key = 0x5D5D5D5D5D5D5D5D,
.plain = 0x5D5D5D5D5D5D5D5D,
.cipher = 0xE812EE6E3572985C,
.decrypted = 0x5D5D5D5D5D5D5D5D,
.iterated_100_times = 0x9F5BA471E525635A,
.iterated_1000_times = 0x87A04AA69F8B46A2
},

{
.key = 0x5E5E5E5E5E5E5E5E,
.plain = 0x5E5E5E5E5E5E5E5E,
.cipher = 0x9BB93A89627BF65F,
.decrypted = 0x5E5E5E5E5E5E5E5E,
.iterated_100_times = 0xEAFA7F35095F910E,
.iterated_1000_times = 0x1B48BCB25C51A005
},

{
.key = 0x5F5F5F5F5F5F5F5F,
.plain = 0x5F5F5F5F5F5F5F5F,
.cipher = 0xEF12476884CB74CA,
.decrypted = 0x5F5F5F5F5F5F5F5F,
.iterated_100_times = 0x7DB85A3FF7275567,
.iterated_1000_times = 0xDB161940B8063D88
},

{
.key = 0x6060606060606060,
.plain = 0x6060606060606060,
.cipher = 0x1BF17E00C09E7CBF,
.decrypted = 0x6060606060606060,
.iterated_100_times = 0x60A4B4FFEDD8D09D,
.iterated_1000_times = 0x029A5E7D28389D02
},

{
.key = 0x6161616161616161,
.plain = 0x6161616161616161,
.cipher = 0x29932350C098DB5D,
.decrypted = 0x6161616161616161,
.iterated_100_times = 0xED8650926D5BE408,
.iterated_1000_times = 0xD005DE4058AA8EE0
},

{
.key = 0x6262626262626262,
.plain = 0x6262626262626262,
.cipher = 0xB476E6499842AC54,
.decrypted = 0x6262626262626262,
.iterated_100_times = 0x51124BFBDA8C6C4D,
.iterated_1000_times = 0x947748735067EE8E
},

{
.key = 0x6363636363636363,
.plain = 0x6363636363636363,
.cipher = 0x5C662C29C1E96056,
.decrypted = 0x6363636363636363,
.iterated_100_times = 0x9127F446AFA01F90,
.iterated_1000_times = 0x5FD86B7379C536EC
},

{
.key = 0x6464646464646464,
.plain = 0x6464646464646464,
.cipher = 0x3AF1703D76442789,
.decrypted = 0x6464646464646464,
.iterated_100_times = 0xFA4A770BAFF12B9D,
.iterated_1000_times = 0xBE1D0835966297C5
},

{
.key = 0x6565656565656565,
.plain = 0x6565656565656565,
.cipher = 0x86405D9B425A8C8C,
.decrypted = 0x6565656565656565,
.iterated_100_times = 0xA968CE8D91FAED99,
.iterated_1000_times = 0x6CFC8EA18C1B4BB5
},

{
.key = 0x6666666666666666,
.plain = 0x6666666666666666,
.cipher = 0xEBBF4810619C2C55,
.decrypted = 0x6666666666666666,
.iterated_100_times = 0x4DC02B7CB96869BB,
.iterated_1000_times = 0xDFC74FA334B18C6F
},

{
.key = 0x6767676767676767,
.plain = 0x6767676767676767,
.cipher = 0xF8D1CD7367B21B5D,
.decrypted = 0x6767676767676767,
.iterated_100_times = 0x0037E1E9B97EF9C3,
.iterated_1000_times = 0xEEFD10CAF2F18319
},

{
.key = 0x6868686868686868,
.plain = 0x6868686868686868,
.cipher = 0x9EE703142BF8D7E2,
.decrypted = 0x6868686868686868,
.iterated_100_times = 0x4E13D13ABC20616C,
.iterated_1000_times = 0xB7019E19F678AEAD
},

{
.key = 0x6969696969696969,
.plain = 0x6969696969696969,
.cipher = 0x5FDFFFC3AAAB0CB3,
.decrypted = 0x6969696969696969,
.iterated_100_times = 0x1F7C5F4EEB57E2C5,
.iterated_1000_times = 0xD23964427BC4C2E8
},

{
.key = 0x6A6A6A6A6A6A6A6A,
.plain = 0x6A6A6A6A6A6A6A6A,
.cipher = 0x26C940AB13574231,
.decrypted = 0x6A6A6A6A6A6A6A6A,
.iterated_100_times = 0xE77E2ED0A869672C,
.iterated_1000_times = 0xDAF3214A731AEAE0
},

{
.key = 0x6B6B6B6B6B6B6B6B,
.plain = 0x6B6B6B6B6B6B6B6B,
.cipher = 0x1E2DC77E36A84693,
.decrypted = 0x6B6B6B6B6B6B6B6B,
.iterated_100_times = 0xDEE6CE5A343AAD73,
.iterated_1000_times = 0xA14CA4D7D4E7A5BC
},

{
.key = 0x6C6C6C6C6C6C6C6C,
.plain = 0x6C6C6C6C6C6C6C6C,
.cipher = 0x0F4FF4D9BC7E2244,
.decrypted = 0x6C6C6C6C6C6C6C6C,
.iterated_100_times = 0x5DFD406F86064F9D,
.iterated_1000_times = 0x6903ECE350FB0EF8
},

{
.key = 0x6D6D6D6D6D6D6D6D,
.plain = 0x6D6D6D6D6D6D6D6D,
.cipher = 0xA4C9A0D04D3280CD,
.decrypted = 0x6D6D6D6D6D6D6D6D,
.iterated_100_times = 0x940C9CCDC211FA4B,
.iterated_1000_times = 0x16C2877110368D1A
},

{
.key = 0x6E6E6E6E6E6E6E6E,
.plain = 0x6E6E6E6E6E6E6E6E,
.cipher = 0x9FAF2C96FE84919D,
.decrypted = 0x6E6E6E6E6E6E6E6E,
.iterated_100_times = 0x79CEC2D4828E2714,
.iterated_1000_times = 0xD5964F85A6E7B786
},

{
.key = 0x6F6F6F6F6F6F6F6F,
.plain = 0x6F6F6F6F6F6F6F6F,
.cipher = 0x115DBC965E6096C8,
.decrypted = 0x6F6F6F6F6F6F6F6F,
.iterated_100_times = 0x8BA557D0AF10030F,
.iterated_1000_times = 0xF8C9D394FC0DC07D
},

{
.key = 0x7070707070707070,
.plain = 0x7070707070707070,
.cipher = 0xAF531E9520994017,
.decrypted = 0x7070707070707070,
.iterated_100_times = 0xA30EA6C2CBE21FCB,
.iterated_1000_times = 0x9AAE92F061E2D684
},

{
.key = 0x7171717171717171,
.plain = 0x7171717171717171,
.cipher = 0xB971ADE70E5C89EE,
.decrypted = 0x7171717171717171,
.iterated_100_times = 0xACE97DAB7556DC0B,
.iterated_1000_times = 0x0F3FBCD85D262DAD
},

{
.key = 0x7272727272727272,
.plain = 0x7272727272727272,
.cipher = 0x415D81C86AF9C376,
.decrypted = 0x7272727272727272,
.iterated_100_times = 0xD9C604DDAA99EDB9,
.iterated_1000_times = 0xE1BAEA2A9C12F809
},

{
.key = 0x7373737373737373,
.plain = 0x7373737373737373,
.cipher = 0x8DFB864FDB3C6811,
.decrypted = 0x7373737373737373,
.iterated_100_times = 0x681DB6359D38B291,
.iterated_1000_times = 0xB3F74991E4F22FB3
},

{
.key = 0x7474747474747474,
.plain = 0x7474747474747474,
.cipher = 0x10B1C170E3398F91,
.decrypted = 0x7474747474747474,
.iterated_100_times = 0xE74C05FE35DD3D57,
.iterated_1000_times = 0x35DBF69F914F6667
},

{
.key = 0x7575757575757575,
.plain = 0x7575757575757575,
.cipher = 0xCFEF7A1C0218DB1E,
.decrypted = 0x7575757575757575,
.iterated_100_times = 0xE7CA1157351E69FD,
.iterated_1000_times = 0x213D47FF935F29BC
},

{
.key = 0x7676767676767676,
.plain = 0x7676767676767676,
.cipher = 0xDBAC30A2A40B1B9C,
.decrypted = 0x7676767676767676,
.iterated_100_times = 0x671DEAD46E44823C,
.iterated_1000_times = 0xEDC55E5C2D3247E2
},

{
.key = 0x7777777777777777,
.plain = 0x7777777777777777,
.cipher = 0x89D3BF37052162E9,
.decrypted = 0x7777777777777777,
.iterated_100_times = 0x8E5B48A6A3BFFC8B,
.iterated_1000_times = 0x0B740BCC8FF4BFCF
},

{
.key = 0x7878787878787878,
.plain = 0x7878787878787878,
.cipher = 0x80D9230BDAEB67DC,
.decrypted = 0x7878787878787878,
.iterated_100_times = 0xF2C537E049166044,
.iterated_1000_times = 0xCA6B600339E48829
},

{
.key = 0x7979797979797979,
.plain = 0x7979797979797979,
.cipher = 0x3440911019AD68D7,
.decrypted = 0x7979797979797979,
.iterated_100_times = 0x538F431DB2B41F67,
.iterated_1000_times = 0x34A250D956BF8D45
},

{
.key = 0x7A7A7A7A7A7A7A7A,
.plain = 0x7A7A7A7A7A7A7A7A,
.cipher = 0x9626FE57596E199E,
.decrypted = 0x7A7A7A7A7A7A7A7A,
.iterated_100_times = 0x4603F97E8B4951C4,
.iterated_1000_times = 0x7ADBC621DF6F4B19
},

{
.key = 0x7B7B7B7B7B7B7B7B,
.plain = 0x7B7B7B7B7B7B7B7B,
.cipher = 0xDEA0B796624BB5BA,
.decrypted = 0x7B7B7B7B7B7B7B7B,
.iterated_100_times = 0xC7EE24A41267ED74,
.iterated_1000_times = 0x0A34B1517C7C4618
},

{
.key = 0x7C7C7C7C7C7C7C7C,
.plain = 0x7C7C7C7C7C7C7C7C,
.cipher = 0xE9E40542BDDB3E9D,
.decrypted = 0x7C7C7C7C7C7C7C7C,
.iterated_100_times = 0x277C8F43A5E0A077,
.iterated_1000_times = 0xE4CE03A6753F2BC4
},

{
.key = 0x7D7D7D7D7D7D7D7D,
.plain = 0x7D7D7D7D7D7D7D7D,
.cipher = 0x8AD99914B354B911,
.decrypted = 0x7D7D7D7D7D7D7D7D,
.iterated_100_times = 0x6AA910EA596A4386,
.iterated_1000_times = 0x839EAD5AB5187F54
},

{
.key = 0x7E7E7E7E7E7E7E7E,
.plain = 0x7E7E7E7E7E7E7E7E,
.cipher = 0x6F85B98DD12CB13B,
.decrypted = 0x7E7E7E7E7E7E7E7E,
.iterated_100_times = 0xECD3B2B72EB3BB15,
.iterated_1000_times = 0x1ED87FEAF3F24593
},

{
.key = 0x7F7F7F7F7F7F7F7F,
.plain = 0x7F7F7F7F7F7F7F7F,
.cipher = 0x10130DA3C3A23924,
.decrypted = 0x7F7F7F7F7F7F7F7F,
.iterated_100_times = 0x1EDB5BE02B8D688A,
.iterated_1000_times = 0x092CE7D5D91A870C
},

{
.key = 0x8080808080808080,
.plain = 0x8080808080808080,
.cipher = 0xEFECF25C3C5DC6DB,
.decrypted = 0x8080808080808080,
.iterated_100_times = 0xE124A41FD4729775,
.iterated_1000_times = 0xF6D3182A26E578F3
},

{
.key = 0x8181818181818181,
.plain = 0x8181818181818181,
.cipher = 0x907A46722ED34EC4,
.decrypted = 0x8181818181818181,
.iterated_100_times = 0x132C4D48D14C44EA,
.iterated_1000_times = 0xE12780150C0DBA6C
},

{
.key = 0x8282828282828282,
.plain = 0x8282828282828282,
.cipher = 0x752666EB4CAB46EE,
.decrypted = 0x8282828282828282,
.iterated_100_times = 0x9556EF15A695BC79,
.iterated_1000_times = 0x7C6152A54AE780AB
},

{
.key = 0x8383838383838383,
.plain = 0x8383838383838383,
.cipher = 0x161BFABD4224C162,
.decrypted = 0x8383838383838383,
.iterated_100_times = 0xD88370BC5A1F5F88,
.iterated_1000_times = 0x1B31FC598AC0D43B
},

{
.key = 0x8484848484848484,
.plain = 0x8484848484848484,
.cipher = 0x215F48699DB44A45,
.decrypted = 0x8484848484848484,
.iterated_100_times = 0x3811DB5BED98128B,
.iterated_1000_times = 0xF5CB4EAE8383B9E7
},

{
.key = 0x8585858585858585,
.plain = 0x8585858585858585,
.cipher = 0x69D901A8A691E661,
.decrypted = 0x8585858585858585,
.iterated_100_times = 0xB9FC068174B6AE3B,
.iterated_1000_times = 0x852439DE2090B4E6
},

{
.key = 0x8686868686868686,
.plain = 0x8686868686868686,
.cipher = 0xCBBF6EEFE6529728,
.decrypted = 0x8686868686868686,
.iterated_100_times = 0xAC70BCE24D4BE098,
.iterated_1000_times = 0xCB5DAF26A94072BA
},

{
.key = 0x8787878787878787,
.plain = 0x8787878787878787,
.cipher = 0x7F26DCF425149823,
.decrypted = 0x8787878787878787,
.iterated_100_times = 0x0D3AC81FB6E99FBB,
.iterated_1000_times = 0x35949FFCC61B77D6
},

{
.key = 0x8888888888888888,
.plain = 0x8888888888888888,
.cipher = 0x762C40C8FADE9D16,
.decrypted = 0x8888888888888888,
.iterated_100_times = 0x71A4B7595C400374,
.iterated_1000_times = 0xF48BF433700B4030
},

{
.key = 0x8989898989898989,
.plain = 0x8989898989898989,
.cipher = 0x2453CF5D5BF4E463,
.decrypted = 0x8989898989898989,
.iterated_100_times = 0x98E2152B91BB7DC3,
.iterated_1000_times = 0x123AA1A3D2CDB81D
},

{
.key = 0x8A8A8A8A8A8A8A8A,
.plain = 0x8A8A8A8A8A8A8A8A,
.cipher = 0x301085E3FDE724E1,
.decrypted = 0x8A8A8A8A8A8A8A8A,
.iterated_100_times = 0x1835EEA8CAE19602,
.iterated_1000_times = 0xDEC2B8006CA0D643
},

{
.key = 0x8B8B8B8B8B8B8B8B,
.plain = 0x8B8B8B8B8B8B8B8B,
.cipher = 0xEF4E3E8F1CC6706E,
.decrypted = 0x8B8B8B8B8B8B8B8B,
.iterated_100_times = 0x18B3FA01CA22C2A8,
.iterated_1000_times = 0xCA2409606EB09998
},

{
.key = 0x8C8C8C8C8C8C8C8C,
.plain = 0x8C8C8C8C8C8C8C8C,
.cipher = 0x720479B024C397EE,
.decrypted = 0x8C8C8C8C8C8C8C8C,
.iterated_100_times = 0x97E249CA62C74D6E,
.iterated_1000_times = 0x4C08B66E1B0DD04C
},

{
.key = 0x8D8D8D8D8D8D8D8D,
.plain = 0x8D8D8D8D8D8D8D8D,
.cipher = 0xBEA27E3795063C89,
.decrypted = 0x8D8D8D8D8D8D8D8D,
.iterated_100_times = 0x2639FB2255661246,
.iterated_1000_times = 0x1E4515D563ED07F6
},

{
.key = 0x8E8E8E8E8E8E8E8E,
.plain = 0x8E8E8E8E8E8E8E8E,
.cipher = 0x468E5218F1A37611,
.decrypted = 0x8E8E8E8E8E8E8E8E,
.iterated_100_times = 0x531682548AA923F4,
.iterated_1000_times = 0xF0C04327A2D9D252
},

{
.key = 0x8F8F8F8F8F8F8F8F,
.plain = 0x8F8F8F8F8F8F8F8F,
.cipher = 0x50ACE16ADF66BFE8,
.decrypted = 0x8F8F8F8F8F8F8F8F,
.iterated_100_times = 0x5CF1593D341DE034,
.iterated_1000_times = 0x65516D0F9E1D297B
},

{
.key = 0x9090909090909090,
.plain = 0x9090909090909090,
.cipher = 0xEEA24369A19F6937,
.decrypted = 0x9090909090909090,
.iterated_100_times = 0x745AA82F50EFFCF0,
.iterated_1000_times = 0x07362C6B03F23F82
},

{
.key = 0x9191919191919191,
.plain = 0x9191919191919191,
.cipher = 0x6050D369017B6E62,
.decrypted = 0x9191919191919191,
.iterated_100_times = 0x86313D2B7D71D8EB,
.iterated_1000_times = 0x2A69B07A59184879
},

{
.key = 0x9292929292929292,
.plain = 0x9292929292929292,
.cipher = 0x5B365F2FB2CD7F32,
.decrypted = 0x9292929292929292,
.iterated_100_times = 0x6BF363323DEE05B4,
.iterated_1000_times = 0xE93D788EEFC972E5
},

{
.key = 0x9393939393939393,
.plain = 0x9393939393939393,
.cipher = 0xF0B00B264381DDBB,
.decrypted = 0x9393939393939393,
.iterated_100_times = 0xA202BF9079F9B062,
.iterated_1000_times = 0x96FC131CAF04F107
},

{
.key = 0x9494949494949494,
.plain = 0x9494949494949494,
.cipher = 0xE1D23881C957B96C,
.decrypted = 0x9494949494949494,
.iterated_100_times = 0x211931A5CBC5528C,
.iterated_1000_times = 0x5EB35B282B185A43
},

{
.key = 0x9595959595959595,
.plain = 0x9595959595959595,
.cipher = 0xD936BF54ECA8BDCE,
.decrypted = 0x9595959595959595,
.iterated_100_times = 0x1881D12F579698D3,
.iterated_1000_times = 0x250CDEB58CE5151F
},

{
.key = 0x9696969696969696,
.plain = 0x9696969696969696,
.cipher = 0xA020003C5554F34C,
.decrypted = 0x9696969696969696,
.iterated_100_times = 0xE083A0B114A81D3A,
.iterated_1000_times = 0x2DC69BBD843B3D17
},

{
.key = 0x9797979797979797,
.plain = 0x9797979797979797,
.cipher = 0x6118FCEBD407281D,
.decrypted = 0x9797979797979797,
.iterated_100_times = 0xB1EC2EC543DF9E93,
.iterated_1000_times = 0x48FE61E609875152
},

{
.key = 0x9898989898989898,
.plain = 0x9898989898989898,
.cipher = 0x072E328C984DE4A2,
.decrypted = 0x9898989898989898,
.iterated_100_times = 0xFFC81E164681063C,
.iterated_1000_times = 0x1102EF350D0E7CE6
},

{
.key = 0x9999999999999999,
.plain = 0x9999999999999999,
.cipher = 0x1440B7EF9E63D3AA,
.decrypted = 0x9999999999999999,
.iterated_100_times = 0xB23FD48346979644,
.iterated_1000_times = 0x2038B05CCB4E7390
},

{
.key = 0x9A9A9A9A9A9A9A9A,
.plain = 0x9A9A9A9A9A9A9A9A,
.cipher = 0x79BFA264BDA57373,
.decrypted = 0x9A9A9A9A9A9A9A9A,
.iterated_100_times = 0x569731726E051266,
.iterated_1000_times = 0x9303715E73E4B44A
},

{
.key = 0x9B9B9B9B9B9B9B9B,
.plain = 0x9B9B9B9B9B9B9B9B,
.cipher = 0xC50E8FC289BBD876,
.decrypted = 0x9B9B9B9B9B9B9B9B,
.iterated_100_times = 0x05B588F4500ED462,
.iterated_1000_times = 0x41E2F7CA699D683A
},

{
.key = 0x9C9C9C9C9C9C9C9C,
.plain = 0x9C9C9C9C9C9C9C9C,
.cipher = 0xA399D3D63E169FA9,
.decrypted = 0x9C9C9C9C9C9C9C9C,
.iterated_100_times = 0x6ED80BB9505FE06F,
.iterated_1000_times = 0xA027948C863AC913
},

{
.key = 0x9D9D9D9D9D9D9D9D,
.plain = 0x9D9D9D9D9D9D9D9D,
.cipher = 0x4B8919B667BD53AB,
.decrypted = 0x9D9D9D9D9D9D9D9D,
.iterated_100_times = 0xAEEDB404257393B2,
.iterated_1000_times = 0x6B88B78CAF981171
},

{
.key = 0x9E9E9E9E9E9E9E9E,
.plain = 0x9E9E9E9E9E9E9E9E,
.cipher = 0xD66CDCAF3F6724A2,
.decrypted = 0x9E9E9E9E9E9E9E9E,
.iterated_100_times = 0x1279AF6D92A41BF7,
.iterated_1000_times = 0x2FFA21BFA755711F
},

{
.key = 0x9F9F9F9F9F9F9F9F,
.plain = 0x9F9F9F9F9F9F9F9F,
.cipher = 0xE40E81FF3F618340,
.decrypted = 0x9F9F9F9F9F9F9F9F,
.iterated_100_times = 0x9F5B4B0012272F62,
.iterated_1000_times = 0xFD65A182D7C762FD
},

{
.key = 0xA0A0A0A0A0A0A0A0,
.plain = 0xA0A0A0A0A0A0A0A0,
.cipher = 0x10EDB8977B348B35,
.decrypted = 0xA0A0A0A0A0A0A0A0,
.iterated_100_times = 0x8247A5C008D8AA98,
.iterated_1000_times = 0x24E9E6BF47F9C277
},

{
.key = 0xA1A1A1A1A1A1A1A1,
.plain = 0xA1A1A1A1A1A1A1A1,
.cipher = 0x6446C5769D8409A0,
.decrypted = 0xA1A1A1A1A1A1A1A1,
.iterated_100_times = 0x150580CAF6A06EF1,
.iterated_1000_times = 0xE4B7434DA3AE5FFA
},

{
.key = 0xA2A2A2A2A2A2A2A2,
.plain = 0xA2A2A2A2A2A2A2A2,
.cipher = 0x17ED1191CA8D67A3,
.decrypted = 0xA2A2A2A2A2A2A2A2,
.iterated_100_times = 0x60A45B8E1ADA9CA5,
.iterated_1000_times = 0x785FB5596074B95D
},

{
.key = 0xA3A3A3A3A3A3A3A3,
.plain = 0xA3A3A3A3A3A3A3A3,
.cipher = 0xB6D8533731BA1318,
.decrypted = 0xA3A3A3A3A3A3A3A3,
.iterated_100_times = 0x5DD29F3368C1B1F7,
.iterated_1000_times = 0xB70A3FB8C9107C9A
},

{
.key = 0xA4A4A4A4A4A4A4A4,
.plain = 0xA4A4A4A4A4A4A4A4,
.cipher = 0xCA439007C7245CD0,
.decrypted = 0xA4A4A4A4A4A4A4A4,
.iterated_100_times = 0x9A83BE9022683185,
.iterated_1000_times = 0x4206C5159F50DD95
},

{
.key = 0xA5A5A5A5A5A5A5A5,
.plain = 0xA5A5A5A5A5A5A5A5,
.cipher = 0x06FC7FDE1C8389E7,
.decrypted = 0xA5A5A5A5A5A5A5A5,
.iterated_100_times = 0xC14508B435AFB023,
.iterated_1000_times = 0xDB73811AFC4F3CE3
},

{
.key = 0xA6A6A6A6A6A6A6A6,
.plain = 0xA6A6A6A6A6A6A6A6,
.cipher = 0x7A3C1F3BD60CB3D8,
.decrypted = 0xA6A6A6A6A6A6A6A6,
.iterated_100_times = 0xA7DEEE1978F89057,
.iterated_1000_times = 0xD89287061504ADC0
},

{
.key = 0xA7A7A7A7A7A7A7A7,
.plain = 0xA7A7A7A7A7A7A7A7,
.cipher = 0xE415D80048DBA848,
.decrypted = 0xA7A7A7A7A7A7A7A7,
.iterated_100_times = 0x78F84466AFC6F8F6,
.iterated_1000_times = 0xAA202817353DC10B
},

{
.key = 0xA8A8A8A8A8A8A8A8,
.plain = 0xA8A8A8A8A8A8A8A8,
.cipher = 0x26F88D30C0FB8302,
.decrypted = 0xA8A8A8A8A8A8A8A8,
.iterated_100_times = 0x0FCBB807FD55E22B,
.iterated_1000_times = 0x0F07082DCD0FE7B1
},

{
.key = 0xA9A9A9A9A9A9A9A9,
.plain = 0xA9A9A9A9A9A9A9A9,
.cipher = 0xD4E00A9EF5E6D8F3,
.decrypted = 0xA9A9A9A9A9A9A9A9,
.iterated_100_times = 0xAF6AC2573127E404,
.iterated_1000_times = 0x0E92F8E841136230
},

{
.key = 0xAAAAAAAAAAAAAAAA,
.plain = 0xAAAAAAAAAAAAAAAA,
.cipher = 0xC4322BE19E9A5A17,
.decrypted = 0xAAAAAAAAAAAAAAAA,
.iterated_100_times = 0xE7901084858D7C5E,
.iterated_1000_times = 0x27C547E57A57FB91
},

{
.key = 0xABABABABABABABAB,
.plain = 0xABABABABABABABAB,
.cipher = 0xACE41A06BFA258EA,
.decrypted = 0xABABABABABABABAB,
.iterated_100_times = 0x4C4A2C014225C67E,
.iterated_1000_times = 0x4F2C63CB6EFB1D81
},

{
.key = 0xACACACACACACACAC,
.plain = 0xACACACACACACACAC,
.cipher = 0xEEAAC6D17880BD56,
.decrypted = 0xACACACACACACACAC,
.iterated_100_times = 0x584AA3355D19AAC3,
.iterated_1000_times = 0x63D6F19CF36891BC
},

{
.key = 0xADADADADADADADAD,
.plain = 0xADADADADADADADAD,
.cipher = 0x3C9A34CA4CB49EEB,
.decrypted = 0xADADADADADADADAD,
.iterated_100_times = 0x8F295E7EDCE705AD,
.iterated_1000_times = 0x8CDC5A66A3BD0496
},

{
.key = 0xAEAEAEAEAEAEAEAE,
.plain = 0xAEAEAEAEAEAEAEAE,
.cipher = 0x9527B0287B75F5A3,
.decrypted = 0xAEAEAEAEAEAEAEAE,
.iterated_100_times = 0xD4FE75067BC2928C,
.iterated_1000_times = 0xA7D9A68C9D5549DC
},

{
.key = 0xAFAFAFAFAFAFAFAF,
.plain = 0xAFAFAFAFAFAFAFAF,
.cipher = 0xF2D9D1BE74376C0C,
.decrypted = 0xAFAFAFAFAFAFAFAF,
.iterated_100_times = 0xBE94969929F78F04,
.iterated_1000_times = 0xF700A926C8AB292F
},

{
.key = 0xB0B0B0B0B0B0B0B0,
.plain = 0xB0B0B0B0B0B0B0B0,
.cipher = 0x939618DF0AEFAAE7,
.decrypted = 0xB0B0B0B0B0B0B0B0,
.iterated_100_times = 0x915D8DB7C20084A3,
.iterated_1000_times = 0x0A4EC98FA69250D0
},

{
.key = 0xB1B1B1B1B1B1B1B1,
.plain = 0xB1B1B1B1B1B1B1B1,
.cipher = 0x24692773CB9F27FE,
.decrypted = 0xB1B1B1B1B1B1B1B1,
.iterated_100_times = 0x86E87969CB2AB444,
.iterated_1000_times = 0xE939517C61D88B43
},

{
.key = 0xB2B2B2B2B2B2B2B2,
.plain = 0xB2B2B2B2B2B2B2B2,
.cipher = 0x38703BA5E2315D1D,
.decrypted = 0xB2B2B2B2B2B2B2B2,
.iterated_100_times = 0x88C1990293D1F759,
.iterated_1000_times = 0x1708564953E737E0
},

{
.key = 0xB3B3B3B3B3B3B3B3,
.plain = 0xB3B3B3B3B3B3B3B3,
.cipher = 0xFCB7E4B7D702E2FB,
.decrypted = 0xB3B3B3B3B3B3B3B3,
.iterated_100_times = 0x731AD9625E0FEEF1,
.iterated_1000_times = 0xE65A7E02CE13749D
},

{
.key = 0xB4B4B4B4B4B4B4B4,
.plain = 0xB4B4B4B4B4B4B4B4,
.cipher = 0x36F0D0B3675704D5,
.decrypted = 0xB4B4B4B4B4B4B4B4,
.iterated_100_times = 0x45AD3DD538B3AF32,
.iterated_1000_times = 0xE685996FB965CFD8
},

{
.key = 0xB5B5B5B5B5B5B5B5,
.plain = 0xB5B5B5B5B5B5B5B5,
.cipher = 0x62D473F539FA0D8B,
.decrypted = 0xB5B5B5B5B5B5B5B5,
.iterated_100_times = 0x19F1753F1039D24F,
.iterated_1000_times = 0x9998937345EB9339
},

{
.key = 0xB6B6B6B6B6B6B6B6,
.plain = 0xB6B6B6B6B6B6B6B6,
.cipher = 0x1533F3ED9BE8EF8E,
.decrypted = 0xB6B6B6B6B6B6B6B6,
.iterated_100_times = 0xEC189852B1B4E6AC,
.iterated_1000_times = 0x8A8F88616BEF9ECD
},

{
.key = 0xB7B7B7B7B7B7B7B7,
.plain = 0xB7B7B7B7B7B7B7B7,
.cipher = 0x9C4EA352599731ED,
.decrypted = 0xB7B7B7B7B7B7B7B7,
.iterated_100_times = 0xEBC9E8DE341B9192,
.iterated_1000_times = 0x3B3FAA0E54D1EB66
},

{
.key = 0xB8B8B8B8B8B8B8B8,
.plain = 0xB8B8B8B8B8B8B8B8,
.cipher = 0xFABBF7C046FD273F,
.decrypted = 0xB8B8B8B8B8B8B8B8,
.iterated_100_times = 0x870B40B93638B52E,
.iterated_1000_times = 0x2B1BD03858F722FC
},

{
.key = 0xB9B9B9B9B9B9B9B9,
.plain = 0xB9B9B9B9B9B9B9B9,
.cipher = 0xB7FE63A61C646F3A,
.decrypted = 0xB9B9B9B9B9B9B9B9,
.iterated_100_times = 0xDF66CFB21A754F65,
.iterated_1000_times = 0x2C5582114A67DF60
},

{
.key = 0xBABABABABABABABA,
.plain = 0xBABABABABABABABA,
.cipher = 0x10ADB6E2AB972BBE,
.decrypted = 0xBABABABABABABABA,
.iterated_100_times = 0x3E46F627A93A0013,
.iterated_1000_times = 0x9ACA4FCC17C810EC
},

{
.key = 0xBBBBBBBBBBBBBBBB,
.plain = 0xBBBBBBBBBBBBBBBB,
.cipher = 0xF91DCAD912332F3B,
.decrypted = 0xBBBBBBBBBBBBBBBB,
.iterated_100_times = 0x49E78FC13609E063,
.iterated_1000_times = 0x66A218546D0707F1
},

{
.key = 0xBCBCBCBCBCBCBCBC,
.plain = 0xBCBCBCBCBCBCBCBC,
.cipher = 0x46E7EF47323A701D,
.decrypted = 0xBCBCBCBCBCBCBCBC,
.iterated_100_times = 0xDC5F85DECFAE2E17,
.iterated_1000_times = 0x36E94603258DE595
},

{
.key = 0xBDBDBDBDBDBDBDBD,
.plain = 0xBDBDBDBDBDBDBDBD,
.cipher = 0x8DB18CCD9692F758,
.decrypted = 0xBDBDBDBDBDBDBDBD,
.iterated_100_times = 0xDCFBF7216B50B7AE,
.iterated_1000_times = 0xE77CC1A3A1287929
},

{
.key = 0xBEBEBEBEBEBEBEBE,
.plain = 0xBEBEBEBEBEBEBEBE,
.cipher = 0xE6207B536AAAEFFC,
.decrypted = 0xBEBEBEBEBEBEBEBE,
.iterated_100_times = 0x0C48478B29AE4F3E,
.iterated_1000_times = 0x3152CE404E6913BF
},

{
.key = 0xBFBFBFBFBFBFBFBF,
.plain = 0xBFBFBFBFBFBFBFBF,
.cipher = 0x92AA224372156A00,
.decrypted = 0xBFBFBFBFBFBFBFBF,
.iterated_100_times = 0x4DA26C3D54FA5BF8,
.iterated_1000_times = 0x164B01489623AE9B
},

{
.key = 0xC0C0C0C0C0C0C0C0,
.plain = 0xC0C0C0C0C0C0C0C0,
.cipher = 0xA3B357885B1E16D2,
.decrypted = 0xC0C0C0C0C0C0C0C0,
.iterated_100_times = 0x5E5CE4083735461F,
.iterated_1000_times = 0x081B484E1DCAEF3E
},

{
.key = 0xC1C1C1C1C1C1C1C1,
.plain = 0xC1C1C1C1C1C1C1C1,
.cipher = 0x169F7629C970C1E5,
.decrypted = 0xC1C1C1C1C1C1C1C1,
.iterated_100_times = 0xABD4BB3FAA4469CB,
.iterated_1000_times = 0x916880243A186FCB
},

{
.key = 0xC2C2C2C2C2C2C2C2,
.plain = 0xC2C2C2C2C2C2C2C2,
.cipher = 0x62F44B247CF1348C,
.decrypted = 0xC2C2C2C2C2C2C2C2,
.iterated_100_times = 0x5E0C315B4C263365,
.iterated_1000_times = 0xE510A9828B6F1387
},

{
.key = 0xC3C3C3C3C3C3C3C3,
.plain = 0xC3C3C3C3C3C3C3C3,
.cipher = 0xAE0FEEB0495932C8,
.decrypted = 0xC3C3C3C3C3C3C3C3,
.iterated_100_times = 0xCF0C8C5182828604,
.iterated_1000_times = 0xF04F4B1AE34B890B
},

{
.key = 0xC4C4C4C4C4C4C4C4,
.plain = 0xC4C4C4C4C4C4C4C4,
.cipher = 0x72DAF2A7C9EA6803,
.decrypted = 0xC4C4C4C4C4C4C4C4,
.iterated_100_times = 0x4390B27175DEB080,
.iterated_1000_times = 0x048C1FE88609A336
},

{
.key = 0xC5C5C5C5C5C5C5C5,
.plain = 0xC5C5C5C5C5C5C5C5,
.cipher = 0x4FB5D5536DA544F4,
.decrypted = 0xC5C5C5C5C5C5C5C5,
.iterated_100_times = 0xA128E4C976737D98,
.iterated_1000_times = 0xD8B1C94C7C209236
},

{
.key = 0xC6C6C6C6C6C6C6C6,
.plain = 0xC6C6C6C6C6C6C6C6,
.cipher = 0x1DD4E65AAF7988B4,
.decrypted = 0xC6C6C6C6C6C6C6C6,
.iterated_100_times = 0x2A7F23AE01CFFDD6,
.iterated_1000_times = 0x64F9D45C03430258
},

{
.key = 0xC7C7C7C7C7C7C7C7,
.plain = 0xC7C7C7C7C7C7C7C7,
.cipher = 0x76BF084C1535A6C6,
.decrypted = 0xC7C7C7C7C7C7C7C7,
.iterated_100_times = 0xAF173D2156728B85,
.iterated_1000_times = 0x0B71BF7ED4312134
},

{
.key = 0xC8C8C8C8C8C8C8C8,
.plain = 0xC8C8C8C8C8C8C8C8,
.cipher = 0xAFEC35B09D36315F,
.decrypted = 0xC8C8C8C8C8C8C8C8,
.iterated_100_times = 0x39E749D9280A6281,
.iterated_1000_times = 0xDBFFB7E205E244D4
},

{
.key = 0xC9C9C9C9C9C9C9C9,
.plain = 0xC9C9C9C9C9C9C9C9,
.cipher = 0xC8078A6148818403,
.decrypted = 0xC9C9C9C9C9C9C9C9,
.iterated_100_times = 0x501381467CF791D6,
.iterated_1000_times = 0xEC23BAE33F766878
},

{
.key = 0xCACACACACACACACA,
.plain = 0xCACACACACACACACA,
.cipher = 0x4DA91CB4124B67FE,
.decrypted = 0xCACACACACACACACA,
.iterated_100_times = 0x1BDF87A8EF8D0991,
.iterated_1000_times = 0x29253121FB35F5CB
},

{
.key = 0xCBCBCBCBCBCBCBCB,
.plain = 0xCBCBCBCBCBCBCBCB,
.cipher = 0x2DABFEB346794C3D,
.decrypted = 0xCBCBCBCBCBCBCBCB,
.iterated_100_times = 0xF7AAF64AE3C8A47F,
.iterated_1000_times = 0xCE16A9944CF1F7E1
},

{
.key = 0xCCCCCCCCCCCCCCCC,
.plain = 0xCCCCCCCCCCCCCCCC,
.cipher = 0xFBCD12C790D21CD7,
.decrypted = 0xCCCCCCCCCCCCCCCC,
.iterated_100_times = 0x7294E708D94A42CF,
.iterated_1000_times = 0x0248929C10FAE522
},

{
.key = 0xCDCDCDCDCDCDCDCD,
.plain = 0xCDCDCDCDCDCDCDCD,
.cipher = 0x536873DB879CC770,
.decrypted = 0xCDCDCDCDCDCDCDCD,
.iterated_100_times = 0xCAC1B6F8A53E6CA9,
.iterated_1000_times = 0x8B679494B758F464
},

{
.key = 0xCECECECECECECECE,
.plain = 0xCECECECECECECECE,
.cipher = 0x9AA159D7309DA7A0,
.decrypted = 0xCECECECECECECECE,
.iterated_100_times = 0x1E0AAD85559A20D4,
.iterated_1000_times = 0xC071914F896C6A60
},

{
.key = 0xCFCFCFCFCFCFCFCF,
.plain = 0xCFCFCFCFCFCFCFCF,
.cipher = 0x0B844B9D8C4EA14A,
.decrypted = 0xCFCFCFCFCFCFCFCF,
.iterated_100_times = 0x8940C3D3F2E3B42F,
.iterated_1000_times = 0xC34230543E0CDE28
},

{
.key = 0xD0D0D0D0D0D0D0D0,
.plain = 0xD0D0D0D0D0D0D0D0,
.cipher = 0x3BBD84CE539E68C4,
.decrypted = 0xD0D0D0D0D0D0D0D0,
.iterated_100_times = 0xA16A00B5E4B8F362,
.iterated_1000_times = 0x076A09BFBBF856EE
},

{
.key = 0xD1D1D1D1D1D1D1D1,
.plain = 0xD1D1D1D1D1D1D1D1,
.cipher = 0xCF3E4F3E026E2C8E,
.decrypted = 0xD1D1D1D1D1D1D1D1,
.iterated_100_times = 0xAE589D8E52F1C5A0,
.iterated_1000_times = 0x2C20397C54982774
},

{
.key = 0xD2D2D2D2D2D2D2D2,
.plain = 0xD2D2D2D2D2D2D2D2,
.cipher = 0x82F85885D542AF58,
.decrypted = 0xD2D2D2D2D2D2D2D2,
.iterated_100_times = 0xD4411D76000AA37A,
.iterated_1000_times = 0xAFE3D98397DD7F4A
},

{
.key = 0xD3D3D3D3D3D3D3D3,
.plain = 0xD3D3D3D3D3D3D3D3,
.cipher = 0x22D334D6493B3CB6,
.decrypted = 0xD3D3D3D3D3D3D3D3,
.iterated_100_times = 0x2C49065E427494EA,
.iterated_1000_times = 0xE57B8518FB451E8A
},

{
.key = 0xD4D4D4D4D4D4D4D4,
.plain = 0xD4D4D4D4D4D4D4D4,
.cipher = 0x47E9CB3E3154D673,
.decrypted = 0xD4D4D4D4D4D4D4D4,
.iterated_100_times = 0xA21FF12CA3238BD7,
.iterated_1000_times = 0x21E69CC1880B24E0
},

{
.key = 0xD5D5D5D5D5D5D5D5,
.plain = 0xD5D5D5D5D5D5D5D5,
.cipher = 0x2352BCC708ADC7E9,
.decrypted = 0xD5D5D5D5D5D5D5D5,
.iterated_100_times = 0x1E806D40132F54A2,
.iterated_1000_times = 0x7FC540256EA7F53E
},

{
.key = 0xD6D6D6D6D6D6D6D6,
.plain = 0xD6D6D6D6D6D6D6D6,
.cipher = 0x8C0F3BA0C8601980,
.decrypted = 0xD6D6D6D6D6D6D6D6,
.iterated_100_times = 0x39EB9BEB28BC65A6,
.iterated_1000_times = 0xB7EBEE17F45EB353
},

{
.key = 0xD7D7D7D7D7D7D7D7,
.plain = 0xD7D7D7D7D7D7D7D7,
.cipher = 0xEE5E9FD70CEF00E9,
.decrypted = 0xD7D7D7D7D7D7D7D7,
.iterated_100_times = 0x37819558FDB55DA2,
.iterated_1000_times = 0x54A2B8E91BB9E6C6
},

{
.key = 0xD8D8D8D8D8D8D8D8,
.plain = 0xD8D8D8D8D8D8D8D8,
.cipher = 0xDEF6BDA6CABF9547,
.decrypted = 0xD8D8D8D8D8D8D8D8,
.iterated_100_times = 0xF9D98BBA295D4D93,
.iterated_1000_times = 0x670C1A86D2A6894E
},

{
.key = 0xD9D9D9D9D9D9D9D9,
.plain = 0xD9D9D9D9D9D9D9D9,
.cipher = 0x4DADD04A0EA70F20,
.decrypted = 0xD9D9D9D9D9D9D9D9,
.iterated_100_times = 0xF545A7D8D7F3CD47,
.iterated_1000_times = 0x5E4B6232F846EFCF
},

{
.key = 0xDADADADADADADADA,
.plain = 0xDADADADADADADADA,
.cipher = 0xC1AA16689EE1B482,
.decrypted = 0xDADADADADADADADA,
.iterated_100_times = 0xEDDC1A877973E109,
.iterated_1000_times = 0x18D782701F5BC7C1
},

{
.key = 0xDBDBDBDBDBDBDBDB,
.plain = 0xDBDBDBDBDBDBDBDB,
.cipher = 0xF45FC26193E69AEE,
.decrypted = 0xDBDBDBDBDBDBDBDB,
.iterated_100_times = 0x510AD6B806F7BAF5,
.iterated_1000_times = 0xD9F80406813DB4A0
},

{
.key = 0xDCDCDCDCDCDCDCDC,
.plain = 0xDCDCDCDCDCDCDCDC,
.cipher = 0xD0CFBB937CEDBFB5,
.decrypted = 0xDCDCDCDCDCDCDCDC,
.iterated_100_times = 0xA01046D5099A9CC5,
.iterated_1000_times = 0x6E9A31352EA9C090
},

{
.key = 0xDDDDDDDDDDDDDDDD,
.plain = 0xDDDDDDDDDDDDDDDD,
.cipher = 0xF0752004EE23D87B,
.decrypted = 0xDDDDDDDDDDDDDDDD,
.iterated_100_times = 0xF82A568A205CF4BF,
.iterated_1000_times = 0x36B419D8522B3E0B
},

{
.key = 0xDEDEDEDEDEDEDEDE,
.plain = 0xDEDEDEDEDEDEDEDE,
.cipher = 0x77A791E28AA464A5,
.decrypted = 0xDEDEDEDEDEDEDEDE,
.iterated_100_times = 0xAC2DB86C28ABF410,
.iterated_1000_times = 0x1B18CF9378AD8579
},

{
.key = 0xDFDFDFDFDFDFDFDF,
.plain = 0xDFDFDFDFDFDFDFDF,
.cipher = 0xE7562A7F56FF4966,
.decrypted = 0xDFDFDFDFDFDFDFDF,
.iterated_100_times = 0x21188ABBADBFDE7B,
.iterated_1000_times = 0x4722B27D4AA0ECB4
},

{
.key = 0xE0E0E0E0E0E0E0E0,
.plain = 0xE0E0E0E0E0E0E0E0,
.cipher = 0xB026913F2CCFB109,
.decrypted = 0xE0E0E0E0E0E0E0E0,
.iterated_100_times = 0xEB72D9FA3361A708,
.iterated_1000_times = 0x44047E11F1C1416B
},

{
.key = 0xE1E1E1E1E1E1E1E1,
.plain = 0xE1E1E1E1E1E1E1E1,
.cipher = 0x0DB572DDCE388AC7,
.decrypted = 0xE1E1E1E1E1E1E1E1,
.iterated_100_times = 0xA5B0C6070E83F938,
.iterated_1000_times = 0xAC7D81230AD59023
},

{
.key = 0xE2E2E2E2E2E2E2E2,
.plain = 0xE2E2E2E2E2E2E2E2,
.cipher = 0xD9FA6595F0C094CA,
.decrypted = 0xE2E2E2E2E2E2E2E2,
.iterated_100_times = 0x07C4796C2F59E696,
.iterated_1000_times = 0x6CEC5AC39FAE424C
},

{
.key = 0xE3E3E3E3E3E3E3E3,
.plain = 0xE3E3E3E3E3E3E3E3,
.cipher = 0xADE4804C4BE4486E,
.decrypted = 0xE3E3E3E3E3E3E3E3,
.iterated_100_times = 0x06EEA346611D62E8,
.iterated_1000_times = 0xBCF94D053EE22F2A
},

{
.key = 0xE4E4E4E4E4E4E4E4,
.plain = 0xE4E4E4E4E4E4E4E4,
.cipher = 0x007B81F520E6D7DA,
.decrypted = 0xE4E4E4E4E4E4E4E4,
.iterated_100_times = 0x310AD55F09FBEDF8,
.iterated_1000_times = 0xBAF5AF88901E2AD2
},

{
.key = 0xE5E5E5E5E5E5E5E5,
.plain = 0xE5E5E5E5E5E5E5E5,
.cipher = 0x961AEB77BFC10B3C,
.decrypted = 0xE5E5E5E5E5E5E5E5,
.iterated_100_times = 0x4E63FF1FEB069184,
.iterated_1000_times = 0x25189FC04ED3B861
},

{
.key = 0xE6E6E6E6E6E6E6E6,
.plain = 0xE6E6E6E6E6E6E6E6,
.cipher = 0x8A8DD870C9B14AF2,
.decrypted = 0xE6E6E6E6E6E6E6E6,
.iterated_100_times = 0xC4259776E0BEE1D8,
.iterated_1000_times = 0x5208CA02F7FB142D
},

{
.key = 0xE7E7E7E7E7E7E7E7,
.plain = 0xE7E7E7E7E7E7E7E7,
.cipher = 0x3CC02E14B6349B25,
.decrypted = 0xE7E7E7E7E7E7E7E7,
.iterated_100_times = 0xF92F2CF7BC897D40,
.iterated_1000_times = 0x6A8C6E2B57191DEF
},

{
.key = 0xE8E8E8E8E8E8E8E8,
.plain = 0xE8E8E8E8E8E8E8E8,
.cipher = 0xBAD3EE68BDDB9607,
.decrypted = 0xE8E8E8E8E8E8E8E8,
.iterated_100_times = 0xDF81B49E79C5E656,
.iterated_1000_times = 0xF1F641415F626C60
},

{
.key = 0xE9E9E9E9E9E9E9E9,
.plain = 0xE9E9E9E9E9E9E9E9,
.cipher = 0xDFF918E93BDAD292,
.decrypted = 0xE9E9E9E9E9E9E9E9,
.iterated_100_times = 0x0C8EB2D653121D23,
.iterated_1000_times = 0x067C671574D53E3D
},

{
.key = 0xEAEAEAEAEAEAEAEA,
.plain = 0xEAEAEAEAEAEAEAEA,
.cipher = 0x8FE559C7CD6FA56D,
.decrypted = 0xEAEAEAEAEAEAEAEA,
.iterated_100_times = 0xF98A3CAD3494D973,
.iterated_1000_times = 0xEE88C13101CBEE0C
},

{
.key = 0xEBEBEBEBEBEBEBEB,
.plain = 0xEBEBEBEBEBEBEBEB,
.cipher = 0xC88480835C1A444C,
.decrypted = 0xEBEBEBEBEBEBEBEB,
.iterated_100_times = 0x05AAA2D794EEA90D,
.iterated_1000_times = 0xB8D801D6EAF580E9
},

{
.key = 0xECECECECECECECEC,
.plain = 0xECECECECECECECEC,
.cipher = 0xD6EE30A16B2CC01E,
.decrypted = 0xECECECECECECECEC,
.iterated_100_times = 0x4A92DE9CCA043A16,
.iterated_1000_times = 0x7FE650510DA82B8F
},

{
.key = 0xEDEDEDEDEDEDEDED,
.plain = 0xEDEDEDEDEDEDEDED,
.cipher = 0x6932D887B2EA9C1A,
.decrypted = 0xEDEDEDEDEDEDEDED,
.iterated_100_times = 0x588ED5B75D7827AA,
.iterated_1000_times = 0xC9A4FED91478578C
},

{
.key = 0xEEEEEEEEEEEEEEEE,
.plain = 0xEEEEEEEEEEEEEEEE,
.cipher = 0x0BFC865461F13ACC,
.decrypted = 0xEEEEEEEEEEEEEEEE,
.iterated_100_times = 0x875EDA82DCCD2B8E,
.iterated_1000_times = 0xC26284F5B1F1CA89
},

{
.key = 0xEFEFEFEFEFEFEFEF,
.plain = 0xEFEFEFEFEFEFEFEF,
.cipher = 0x228AEA0D403E807A,
.decrypted = 0xEFEFEFEFEFEFEFEF,
.iterated_100_times = 0xA61B4DF5D461EC5B,
.iterated_1000_times = 0xACD1CB4D9F1E8E47
},

{
.key = 0xF0F0F0F0F0F0F0F0,
.plain = 0xF0F0F0F0F0F0F0F0,
.cipher = 0x2A2891F65BB8173C,
.decrypted = 0xF0F0F0F0F0F0F0F0,
.iterated_100_times = 0xD7FBEF924B9DBCE0,
.iterated_1000_times = 0xD9EB0B9EF30F5BD0
},

{
.key = 0xF1F1F1F1F1F1F1F1,
.plain = 0xF1F1F1F1F1F1F1F1,
.cipher = 0x5D1B8FAF7839494B,
.decrypted = 0xF1F1F1F1F1F1F1F1,
.iterated_100_times = 0xF7FF951E56078674,
.iterated_1000_times = 0xD07242D7A2ACAC38
},

{
.key = 0xF2F2F2F2F2F2F2F2,
.plain = 0xF2F2F2F2F2F2F2F2,
.cipher = 0x1C0A9280EECF5D48,
.decrypted = 0xF2F2F2F2F2F2F2F2,
.iterated_100_times = 0x8F139650FA13BB89,
.iterated_1000_times = 0x9B0E0B4C799A3812
},

{
.key = 0xF3F3F3F3F3F3F3F3,
.plain = 0xF3F3F3F3F3F3F3F3,
.cipher = 0x6CBCE951BBC30F74,
.decrypted = 0xF3F3F3F3F3F3F3F3,
.iterated_100_times = 0x129D99F0D7BCBC32,
.iterated_1000_times = 0xC24BD701D79829DF
},

{
.key = 0xF4F4F4F4F4F4F4F4,
.plain = 0xF4F4F4F4F4F4F4F4,
.cipher = 0x9CA66E96BD08BC70,
.decrypted = 0xF4F4F4F4F4F4F4F4,
.iterated_100_times = 0x8B084C0FA81AC1B6,
.iterated_1000_times = 0x2233042573AC5B8D
},

{
.key = 0xF5F5F5F5F5F5F5F5,
.plain = 0xF5F5F5F5F5F5F5F5,
.cipher = 0xF5D779FCFBB28BF3,
.decrypted = 0xF5F5F5F5F5F5F5F5,
.iterated_100_times = 0x3B34FF71C5F59D56,
.iterated_1000_times = 0x407049FF9C2C8C51
},

{
.key = 0xF6F6F6F6F6F6F6F6,
.plain = 0xF6F6F6F6F6F6F6F6,
.cipher = 0x0FEC6BBF9B859184,
.decrypted = 0xF6F6F6F6F6F6F6F6,
.iterated_100_times = 0x42CB12CA843C6C74,
.iterated_1000_times = 0xC6BB5B0DCEDC6036
},

{
.key = 0xF7F7F7F7F7F7F7F7,
.plain = 0xF7F7F7F7F7F7F7F7,
.cipher = 0xEF88D2BF052DBDA8,
.decrypted = 0xF7F7F7F7F7F7F7F7,
.iterated_100_times = 0x24CDEB52C4CA3A8D,
.iterated_1000_times = 0xB175BF935B0143AD
},

{
.key = 0xF8F8F8F8F8F8F8F8,
.plain = 0xF8F8F8F8F8F8F8F8,
.cipher = 0x39ADBDDB7363090D,
.decrypted = 0xF8F8F8F8F8F8F8F8,
.iterated_100_times = 0x21C5E8CE5E2CCDB4,
.iterated_1000_times = 0x3643DA284291B2BC
},

{
.key = 0xF9F9F9F9F9F9F9F9,
.plain = 0xF9F9F9F9F9F9F9F9,
.cipher = 0xC0AEAF445F7E2A7A,
.decrypted = 0xF9F9F9F9F9F9F9F9,
.iterated_100_times = 0x2E3A9FF184E7944E,
.iterated_1000_times = 0xD8ADD64A2DAC9AC9
},

{
.key = 0xFAFAFAFAFAFAFAFA,
.plain = 0xFAFAFAFAFAFAFAFA,
.cipher = 0xC66F54067298D4E9,
.decrypted = 0xFAFAFAFAFAFAFAFA,
.iterated_100_times = 0x01B55881017AE5A7,
.iterated_1000_times = 0xBCB275378350A650
},

{
.key = 0xFBFBFBFBFBFBFBFB,
.plain = 0xFBFBFBFBFBFBFBFB,
.cipher = 0xE0BA8F4488AAF97C,
.decrypted = 0xFBFBFBFBFBFBFBFB,
.iterated_100_times = 0x36A03F5910917129,
.iterated_1000_times = 0xC8C52214145F197E
},

{
.key = 0xFCFCFCFCFCFCFCFC,
.plain = 0xFCFCFCFCFCFCFCFC,
.cipher = 0x67B36E2875D9631C,
.decrypted = 0xFCFCFCFCFCFCFCFC,
.iterated_100_times = 0x0B928013B6E2FB64,
.iterated_1000_times = 0xE4AB2DCB637F4B0D
},

{
.key = 0xFDFDFDFDFDFDFDFD,
.plain = 0xFDFDFDFDFDFDFDFD,
.cipher = 0x1ED83D49E267191D,
.decrypted = 0xFDFDFDFDFDFDFDFD,
.iterated_100_times = 0x4A8A081FC944218D,
.iterated_1000_times = 0x109914EF6ADC7044
},

{
.key = 0xFEFEFEFEFEFEFEFE,
.plain = 0xFEFEFEFEFEFEFEFE,
.cipher = 0x66B2B23EA84693AD,
.decrypted = 0xFEFEFEFEFEFEFEFE,
.iterated_100_times = 0xFEFEFEFEFEFEFEFE,
.iterated_1000_times = 0xFEFEFEFEFEFEFEFE
},

{
.key = 0xFFFFFFFFFFFFFFFF,
.plain = 0xFFFFFFFFFFFFFFFF,
.cipher = 0x7359B2163E4EDC58,
.decrypted = 0xFFFFFFFFFFFFFFFF,
.iterated_100_times = 0xFFFFFFFFFFFFFFFF,
.iterated_1000_times = 0xFFFFFFFFFFFFFFFF
},

//Test vectors -- set 4
//==================== =

{
.key = 0x0001020304050607,
.plain = 0x0011223344556677,
.cipher = 0x3EF0A891CF8ED990,
.decrypted = 0x0011223344556677,
.iterated_100_times = 0x197A7BD2A46DAD16,
.iterated_1000_times = 0x12535CB0F77EE77C
},

{
.key = 0x2BD6459F82C5B300,
.plain = 0xEA024714AD5C4D84,
.cipher = 0x126EFE8ED312190A,
.decrypted = 0xEA024714AD5C4D84,
.iterated_100_times = 0xC19434F73864A3F6,
.iterated_1000_times = 0xCC3FD23E36545FAE
},

//Test vectors -- set 5
//==================== =

{
.key = 0x8000000000000000,
.cipher = 0x0000000000000000,
.plain = 0x1C29EEE68829F666,
.encrypted = 0x0000000000000000
},

{
.key = 0x4000000000000000,
.cipher = 0x0000000000000000,
.plain = 0x1EBAA7E2844108D1,
.encrypted = 0x0000000000000000
},

{
.key = 0x2000000000000000,
.cipher = 0x0000000000000000,
.plain = 0xDD75FF6DD1D07407,
.encrypted = 0x0000000000000000
},

{
.key = 0x1000000000000000,
.cipher = 0x0000000000000000,
.plain = 0x6C0D0366D7FC1E93,
.encrypted = 0x0000000000000000
},

{
.key = 0x0800000000000000,
.cipher = 0x0000000000000000,
.plain = 0x65FB4EDB3731E927,
.encrypted = 0x0000000000000000
},

{
.key = 0x0400000000000000,
.cipher = 0x0000000000000000,
.plain = 0x1A4795892BD82629,
.encrypted = 0x0000000000000000
},

{
.key = 0x0200000000000000,
.cipher = 0x0000000000000000,
.plain = 0x6E228A9F47A31527,
.encrypted = 0x0000000000000000
},

{
.key = 0x0100000000000000,
.cipher = 0x0000000000000000,
.plain = 0x8CA64DE9C1B123A7,
.encrypted = 0x0000000000000000
},

{
.key = 0x0080000000000000,
.cipher = 0x0000000000000000,
.plain = 0x5A01EA0528FE4DBC,
.encrypted = 0x0000000000000000
},

{
.key = 0x0040000000000000,
.cipher = 0x0000000000000000,
.plain = 0x2AA7048B7F843ACC,
.encrypted = 0x0000000000000000
},

{
.key = 0x0020000000000000,
.cipher = 0x0000000000000000,
.plain = 0xFB1426125A5AE00F,
.encrypted = 0x0000000000000000
},

{
.key = 0x0010000000000000,
.cipher = 0x0000000000000000,
.plain = 0x3ACC2A83D9FE0CF8,
.encrypted = 0x0000000000000000
},

{
.key = 0x0008000000000000,
.cipher = 0x0000000000000000,
.plain = 0x2616451A5426B97D,
.encrypted = 0x0000000000000000
},

{
.key = 0x0004000000000000,
.cipher = 0x0000000000000000,
.plain = 0xB85395BAA402FFB9,
.encrypted = 0x0000000000000000
},

{
.key = 0x0002000000000000,
.cipher = 0x0000000000000000,
.plain = 0xD02182A2E8E573A1,
.encrypted = 0x0000000000000000
},

{
.key = 0x0001000000000000,
.cipher = 0x0000000000000000,
.plain = 0x8CA64DE9C1B123A7,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000800000000000,
.cipher = 0x0000000000000000,
.plain = 0xC6ED12A06A4CC156,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000400000000000,
.cipher = 0x0000000000000000,
.plain = 0x64EEA4A26D381E26,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000200000000000,
.cipher = 0x0000000000000000,
.plain = 0x4EA9D5AA0C2C3C4E,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000100000000000,
.cipher = 0x0000000000000000,
.plain = 0x8D8661C34C6F4D21,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000080000000000,
.cipher = 0x0000000000000000,
.plain = 0xE3FF48ACC26B8A33,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000040000000000,
.cipher = 0x0000000000000000,
.plain = 0xC57374F43AF34F17,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000020000000000,
.cipher = 0x0000000000000000,
.plain = 0x857FB4722F85F57F,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000010000000000,
.cipher = 0x0000000000000000,
.plain = 0x8CA64DE9C1B123A7,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000008000000000,
.cipher = 0x0000000000000000,
.plain = 0xD86AFF1EE01AAA00,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000004000000000,
.cipher = 0x0000000000000000,
.plain = 0x7B4937859794FC5E,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000002000000000,
.cipher = 0x0000000000000000,
.plain = 0x05EF338303C238D9,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000001000000000,
.cipher = 0x0000000000000000,
.plain = 0x0E2F05283A7DD2B2,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000800000000,
.cipher = 0x0000000000000000,
.plain = 0x661502A71B53EAD4,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000400000000,
.cipher = 0x0000000000000000,
.plain = 0x1EBBFCECD36FA671,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000200000000,
.cipher = 0x0000000000000000,
.plain = 0x6800E59AF69486CD,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000100000000,
.cipher = 0x0000000000000000,
.plain = 0x8CA64DE9C1B123A7,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000080000000,
.cipher = 0x0000000000000000,
.plain = 0x82453A94E658B38D,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000040000000,
.cipher = 0x0000000000000000,
.plain = 0xBD0622EBC5E34C41,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000020000000,
.cipher = 0x0000000000000000,
.plain = 0x4C3E34B8BE70C9F2,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000010000000,
.cipher = 0x0000000000000000,
.plain = 0x1027E471BF185728,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000008000000,
.cipher = 0x0000000000000000,
.plain = 0x39DE1CB6FE1959A4,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000004000000,
.cipher = 0x0000000000000000,
.plain = 0xE3C3CC1A68B58E5D,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000002000000,
.cipher = 0x0000000000000000,
.plain = 0xB60F05703D5012FA,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000001000000,
.cipher = 0x0000000000000000,
.plain = 0x8CA64DE9C1B123A7,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000000800000,
.cipher = 0x0000000000000000,
.plain = 0xD19667C59D94D4F7,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000000400000,
.cipher = 0x0000000000000000,
.plain = 0x3CA5963292ED8725,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000000200000,
.cipher = 0x0000000000000000,
.plain = 0x1F2B2104BF62E510,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000000100000,
.cipher = 0x0000000000000000,
.plain = 0x322D5F2AD1F6C3F8,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000000080000,
.cipher = 0x0000000000000000,
.plain = 0x202D8D2E16C3DE65,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000000040000,
.cipher = 0x0000000000000000,
.plain = 0x10B71036AF979F7A,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000000020000,
.cipher = 0x0000000000000000,
.plain = 0x980048358ADB5189,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000000010000,
.cipher = 0x0000000000000000,
.plain = 0x8CA64DE9C1B123A7,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000000008000,
.cipher = 0x0000000000000000,
.plain = 0x737589DC3ADDB4D5,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000000004000,
.cipher = 0x0000000000000000,
.plain = 0xF7900FD046800D04,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000000002000,
.cipher = 0x0000000000000000,
.plain = 0x95BE3F4238740526,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000000001000,
.cipher = 0x0000000000000000,
.plain = 0x656F2445A164F9E1,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000000000800,
.cipher = 0x0000000000000000,
.plain = 0x6C77909A14006365,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000000000400,
.cipher = 0x0000000000000000,
.plain = 0xB3524D3045B44663,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000000000200,
.cipher = 0x0000000000000000,
.plain = 0x4BFE8E87CFF074F7,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000000000100,
.cipher = 0x0000000000000000,
.plain = 0x8CA64DE9C1B123A7,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000000000080,
.cipher = 0x0000000000000000,
.plain = 0x0EBFE2B0D89F9EC3,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000000000040,
.cipher = 0x0000000000000000,
.plain = 0xA34785BBA566D0D5,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000000000020,
.cipher = 0x0000000000000000,
.plain = 0xF2B12EA4CF8F6FC2,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000000000010,
.cipher = 0x0000000000000000,
.plain = 0x5D65F4BD79E2AD83,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000000000008,
.cipher = 0x0000000000000000,
.plain = 0x6D2D1CC9A52139BD,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000000000004,
.cipher = 0x0000000000000000,
.plain = 0x6CB9F25ABAAA9DDD,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000000000002,
.cipher = 0x0000000000000000,
.plain = 0x2F3F20C13DEF464C,
.encrypted = 0x0000000000000000
},

{
.key = 0x0000000000000001,
.cipher = 0x0000000000000000,
.plain = 0x8CA64DE9C1B123A7,
.encrypted = 0x0000000000000000
},

//Test vectors -- set 6
//==================== =

{
.key = 0x0000000000000000,
.cipher = 0x8000000000000000,
.plain = 0x95F8A5E5DD31D900,
.encrypted = 0x8000000000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x4000000000000000,
.plain = 0xDD7F121CA5015619,
.encrypted = 0x4000000000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x2000000000000000,
.plain = 0x2E8653104F3834EA,
.encrypted = 0x2000000000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x1000000000000000,
.plain = 0x4BD388FF6CD81D4F,
.encrypted = 0x1000000000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0800000000000000,
.plain = 0x20B9E767B2FB1456,
.encrypted = 0x0800000000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0400000000000000,
.plain = 0x55579380D77138EF,
.encrypted = 0x0400000000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0200000000000000,
.plain = 0x6CC5DEFAAF04512F,
.encrypted = 0x0200000000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0100000000000000,
.plain = 0x0D9F279BA5D87260,
.encrypted = 0x0100000000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0080000000000000,
.plain = 0xD9031B0271BD5A0A,
.encrypted = 0x0080000000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0040000000000000,
.plain = 0x424250B37C3DD951,
.encrypted = 0x0040000000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0020000000000000,
.plain = 0xB8061B7ECD9A21E5,
.encrypted = 0x0020000000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0010000000000000,
.plain = 0xF15D0F286B65BD28,
.encrypted = 0x0010000000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0008000000000000,
.plain = 0xADD0CC8D6E5DEBA1,
.encrypted = 0x0008000000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0004000000000000,
.plain = 0xE6D5F82752AD63D1,
.encrypted = 0x0004000000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0002000000000000,
.plain = 0xECBFE3BD3F591A5E,
.encrypted = 0x0002000000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0001000000000000,
.plain = 0xF356834379D165CD,
.encrypted = 0x0001000000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000800000000000,
.plain = 0x2B9F982F20037FA9,
.encrypted = 0x0000800000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000400000000000,
.plain = 0x889DE068A16F0BE6,
.encrypted = 0x0000400000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000200000000000,
.plain = 0xE19E275D846A1298,
.encrypted = 0x0000200000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000100000000000,
.plain = 0x329A8ED523D71AEC,
.encrypted = 0x0000100000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000080000000000,
.plain = 0xE7FCE22557D23C97,
.encrypted = 0x0000080000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000040000000000,
.plain = 0x12A9F5817FF2D65D,
.encrypted = 0x0000040000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000020000000000,
.plain = 0xA484C3AD38DC9C19,
.encrypted = 0x0000020000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000010000000000,
.plain = 0xFBE00A8A1EF8AD72,
.encrypted = 0x0000010000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000008000000000,
.plain = 0x750D079407521363,
.encrypted = 0x0000008000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000004000000000,
.plain = 0x64FEED9C724C2FAF,
.encrypted = 0x0000004000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000002000000000,
.plain = 0xF02B263B328E2B60,
.encrypted = 0x0000002000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000001000000000,
.plain = 0x9D64555A9A10B852,
.encrypted = 0x0000001000000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000800000000,
.plain = 0xD106FF0BED5255D7,
.encrypted = 0x0000000800000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000400000000,
.plain = 0xE1652C6B138C64A5,
.encrypted = 0x0000000400000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000200000000,
.plain = 0xE428581186EC8F46,
.encrypted = 0x0000000200000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000100000000,
.plain = 0xAEB5F5EDE22D1A36,
.encrypted = 0x0000000100000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000080000000,
.plain = 0xE943D7568AEC0C5C,
.encrypted = 0x0000000080000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000040000000,
.plain = 0xDF98C8276F54B04B,
.encrypted = 0x0000000040000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000020000000,
.plain = 0xB160E4680F6C696F,
.encrypted = 0x0000000020000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000010000000,
.plain = 0xFA0752B07D9C4AB8,
.encrypted = 0x0000000010000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000008000000,
.plain = 0xCA3A2B036DBC8502,
.encrypted = 0x0000000008000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000004000000,
.plain = 0x5E0905517BB59BCF,
.encrypted = 0x0000000004000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000002000000,
.plain = 0x814EEB3B91D90726,
.encrypted = 0x0000000002000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000001000000,
.plain = 0x4D49DB1532919C9F,
.encrypted = 0x0000000001000000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000000800000,
.plain = 0x25EB5FC3F8CF0621,
.encrypted = 0x0000000000800000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000000400000,
.plain = 0xAB6A20C0620D1C6F,
.encrypted = 0x0000000000400000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000000200000,
.plain = 0x79E90DBC98F92CCA,
.encrypted = 0x0000000000200000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000000100000,
.plain = 0x866ECEDD8072BB0E,
.encrypted = 0x0000000000100000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000000080000,
.plain = 0x8B54536F2F3E64A8,
.encrypted = 0x0000000000080000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000000040000,
.plain = 0xEA51D3975595B86B,
.encrypted = 0x0000000000040000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000000020000,
.plain = 0xCAFFC6AC4542DE31,
.encrypted = 0x0000000000020000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000000010000,
.plain = 0x8DD45A2DDF90796C,
.encrypted = 0x0000000000010000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000000008000,
.plain = 0x1029D55E880EC2D0,
.encrypted = 0x0000000000008000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000000004000,
.plain = 0x5D86CB23639DBEA9,
.encrypted = 0x0000000000004000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000000002000,
.plain = 0x1D1CA853AE7C0C5F,
.encrypted = 0x0000000000002000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000000001000,
.plain = 0xCE332329248F3228,
.encrypted = 0x0000000000001000
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000000000800,
.plain = 0x8405D1ABE24FB942,
.encrypted = 0x0000000000000800
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000000000400,
.plain = 0xE643D78090CA4207,
.encrypted = 0x0000000000000400
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000000000200,
.plain = 0x48221B9937748A23,
.encrypted = 0x0000000000000200
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000000000100,
.plain = 0xDD7C0BBD61FAFD54,
.encrypted = 0x0000000000000100
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000000000080,
.plain = 0x2FBC291A570DB5C4,
.encrypted = 0x0000000000000080
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000000000040,
.plain = 0xE07C30D7E4E26E12,
.encrypted = 0x0000000000000040
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000000000020,
.plain = 0x0953E2258E8E90A1,
.encrypted = 0x0000000000000020
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000000000010,
.plain = 0x5B711BC4CEEBF2EE,
.encrypted = 0x0000000000000010
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000000000008,
.plain = 0xCC083F1E6D9E85F6,
.encrypted = 0x0000000000000008
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000000000004,
.plain = 0xD2FD8867D50D2DFE,
.encrypted = 0x0000000000000004
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000000000002,
.plain = 0x06E7EA22CE92708F,
.encrypted = 0x0000000000000002
},

{
.key = 0x0000000000000000,
.cipher = 0x0000000000000001,
.plain = 0x166B40B44ABA4BD6,
.encrypted = 0x0000000000000001
},

//Test vectors -- set 7
//==================== =

{
.key = 0x0000000000000000,
.cipher = 0x0000000000000000,
.plain = 0x8CA64DE9C1B123A7,
.encrypted = 0x0000000000000000
},

{
.key = 0x0101010101010101,
.cipher = 0x0101010101010101,
.plain = 0x994D4DC157B96C52,
.encrypted = 0x0101010101010101
},

{
.key = 0x0202020202020202,
.cipher = 0x0202020202020202,
.plain = 0xF09FA63CCDFA2BAD,
.encrypted = 0x0202020202020202
},

{
.key = 0x0303030303030303,
.cipher = 0x0303030303030303,
.plain = 0x918C7AEFF893AD51,
.encrypted = 0x0303030303030303
},

{
.key = 0x0404040404040404,
.cipher = 0x0404040404040404,
.plain = 0x8991C0C48CF0AF81,
.encrypted = 0x0404040404040404
},

{
.key = 0x0505050505050505,
.cipher = 0x0505050505050505,
.plain = 0x25676954529031CB,
.encrypted = 0x0505050505050505
},

{
.key = 0x0606060606060606,
.cipher = 0x0606060606060606,
.plain = 0xAAEF9DD11DE74546,
.encrypted = 0x0606060606060606
},

{
.key = 0x0707070707070707,
.cipher = 0x0707070707070707,
.plain = 0x8DFFA9A0B2F2548B,
.encrypted = 0x0707070707070707
},

{
.key = 0x0808080808080808,
.cipher = 0x0808080808080808,
.plain = 0xD932847445DA4FD8,
.encrypted = 0x0808080808080808
},

{
.key = 0x0909090909090909,
.cipher = 0x0909090909090909,
.plain = 0x5110E59AAEC7335B,
.encrypted = 0x0909090909090909
},

{
.key = 0x0A0A0A0A0A0A0A0A,
.cipher = 0x0A0A0A0A0A0A0A0A,
.plain = 0xCE681111BA3B7B11,
.encrypted = 0x0A0A0A0A0A0A0A0A
},

{
.key = 0x0B0B0B0B0B0B0B0B,
.cipher = 0x0B0B0B0B0B0B0B0B,
.plain = 0xB5AD1C8C49965CCA,
.encrypted = 0x0B0B0B0B0B0B0B0B
},

{
.key = 0x0C0C0C0C0C0C0C0C,
.cipher = 0x0C0C0C0C0C0C0C0C,
.plain = 0x9F9958F3E2767EA7,
.encrypted = 0x0C0C0C0C0C0C0C0C
},

{
.key = 0x0D0D0D0D0D0D0D0D,
.cipher = 0x0D0D0D0D0D0D0D0D,
.plain = 0x149D6492A0D809EE,
.encrypted = 0x0D0D0D0D0D0D0D0D
},

{
.key = 0x0E0E0E0E0E0E0E0E,
.cipher = 0x0E0E0E0E0E0E0E0E,
.plain = 0xF1EDC5B1F98F6313,
.encrypted = 0x0E0E0E0E0E0E0E0E
},

{
.key = 0x0F0F0F0F0F0F0F0F,
.cipher = 0x0F0F0F0F0F0F0F0F,
.plain = 0x57057A2B85367BED,
.encrypted = 0x0F0F0F0F0F0F0F0F
},

{
.key = 0x1010101010101010,
.cipher = 0x1010101010101010,
.plain = 0xB376C874E6F987D0,
.encrypted = 0x1010101010101010
},

{
.key = 0x1111111111111111,
.cipher = 0x1111111111111111,
.plain = 0x237B2304C393D3AC,
.encrypted = 0x1111111111111111
},

{
.key = 0x1212121212121212,
.cipher = 0x1212121212121212,
.plain = 0xA2F68A96740E3F2D,
.encrypted = 0x1212121212121212
},

{
.key = 0x1313131313131313,
.cipher = 0x1313131313131313,
.plain = 0x1D779D8AB79E89EF,
.encrypted = 0x1313131313131313
},

{
.key = 0x1414141414141414,
.cipher = 0x1414141414141414,
.plain = 0x1E59064FFEA191EF,
.encrypted = 0x1414141414141414
},

{
.key = 0x1515151515151515,
.cipher = 0x1515151515151515,
.plain = 0x53B4DAE06761FFA1,
.encrypted = 0x1515151515151515
},

{
.key = 0x1616161616161616,
.cipher = 0x1616161616161616,
.plain = 0x550FB1A5507A49ED,
.encrypted = 0x1616161616161616
},

{
.key = 0x1717171717171717,
.cipher = 0x1717171717171717,
.plain = 0x64FFAFFBB608B002,
.encrypted = 0x1717171717171717
},

{
.key = 0x1818181818181818,
.cipher = 0x1818181818181818,
.plain = 0x2EF928E663986E1C,
.encrypted = 0x1818181818181818
},

{
.key = 0x1919191919191919,
.cipher = 0x1919191919191919,
.plain = 0x9C7EB95CB182233E,
.encrypted = 0x1919191919191919
},

{
.key = 0x1A1A1A1A1A1A1A1A,
.cipher = 0x1A1A1A1A1A1A1A1A,
.plain = 0xB62CFEB46DD18577,
.encrypted = 0x1A1A1A1A1A1A1A1A
},

{
.key = 0x1B1B1B1B1B1B1B1B,
.cipher = 0x1B1B1B1B1B1B1B1B,
.plain = 0x8F9F498CBA6DF908,
.encrypted = 0x1B1B1B1B1B1B1B1B
},

{
.key = 0x1C1C1C1C1C1C1C1C,
.cipher = 0x1C1C1C1C1C1C1C1C,
.plain = 0x3017633FB8197C95,
.encrypted = 0x1C1C1C1C1C1C1C1C
},

{
.key = 0x1D1D1D1D1D1D1D1D,
.cipher = 0x1D1D1D1D1D1D1D1D,
.plain = 0x079FA37ED80BA064,
.encrypted = 0x1D1D1D1D1D1D1D1D
},

{
.key = 0x1E1E1E1E1E1E1E1E,
.cipher = 0x1E1E1E1E1E1E1E1E,
.plain = 0xC8040684A207D1B5,
.encrypted = 0x1E1E1E1E1E1E1E1E
},

{
.key = 0x1F1F1F1F1F1F1F1F,
.cipher = 0x1F1F1F1F1F1F1F1F,
.plain = 0x61B145D97C491523,
.encrypted = 0x1F1F1F1F1F1F1F1F
},

{
.key = 0x2020202020202020,
.cipher = 0x2020202020202020,
.plain = 0x9073C79790306F7D,
.encrypted = 0x2020202020202020
},

{
.key = 0x2121212121212121,
.cipher = 0x2121212121212121,
.plain = 0xA80B2BFEBE10A4DA,
.encrypted = 0x2121212121212121
},

{
.key = 0x2222222222222222,
.cipher = 0x2222222222222222,
.plain = 0xD105F93010B3B6F5,
.encrypted = 0x2222222222222222
},

{
.key = 0x2323232323232323,
.cipher = 0x2323232323232323,
.plain = 0x8F521B75483A0B94,
.encrypted = 0x2323232323232323
},

{
.key = 0x2424242424242424,
.cipher = 0x2424242424242424,
.plain = 0xC8F028A3EE60B289,
.encrypted = 0x2424242424242424
},

{
.key = 0x2525252525252525,
.cipher = 0x2525252525252525,
.plain = 0xDC8D45D7517FB58C,
.encrypted = 0x2525252525252525
},

{
.key = 0x2626262626262626,
.cipher = 0x2626262626262626,
.plain = 0xA827E72CD184555E,
.encrypted = 0x2626262626262626
},

{
.key = 0x2727272727272727,
.cipher = 0x2727272727272727,
.plain = 0x11A586CDC15F4B62,
.encrypted = 0x2727272727272727
},

{
.key = 0x2828282828282828,
.cipher = 0x2828282828282828,
.plain = 0x6066EF85FF1F8A46,
.encrypted = 0x2828282828282828
},

{
.key = 0x2929292929292929,
.cipher = 0x2929292929292929,
.plain = 0x64F017F35A3F50D1,
.encrypted = 0x2929292929292929
},

{
.key = 0x2A2A2A2A2A2A2A2A,
.cipher = 0x2A2A2A2A2A2A2A2A,
.plain = 0x19D9B4C305AB5AC4,
.encrypted = 0x2A2A2A2A2A2A2A2A
},

{
.key = 0x2B2B2B2B2B2B2B2B,
.cipher = 0x2B2B2B2B2B2B2B2B,
.plain = 0xD13BE446B15397C0,
.encrypted = 0x2B2B2B2B2B2B2B2B
},

{
.key = 0x2C2C2C2C2C2C2C2C,
.cipher = 0x2C2C2C2C2C2C2C2C,
.plain = 0xA1AAAC9B6D3DAB0A,
.encrypted = 0x2C2C2C2C2C2C2C2C
},

{
.key = 0x2D2D2D2D2D2D2D2D,
.cipher = 0x2D2D2D2D2D2D2D2D,
.plain = 0x60EF54CED063EEAC,
.encrypted = 0x2D2D2D2D2D2D2D2D
},

{
.key = 0x2E2E2E2E2E2E2E2E,
.cipher = 0x2E2E2E2E2E2E2E2E,
.plain = 0x659EF16E9EFFC16D,
.encrypted = 0x2E2E2E2E2E2E2E2E
},

{
.key = 0x2F2F2F2F2F2F2F2F,
.cipher = 0x2F2F2F2F2F2F2F2F,
.plain = 0x7F991C35E71F8D95,
.encrypted = 0x2F2F2F2F2F2F2F2F
},

{
.key = 0x3030303030303030,
.cipher = 0x3030303030303030,
.plain = 0x335AC5E54AA4C5FA,
.encrypted = 0x3030303030303030
},

{
.key = 0x3131313131313131,
.cipher = 0x3131313131313131,
.plain = 0x6D0A7ECC98A019A6,
.encrypted = 0x3131313131313131
},

{
.key = 0x3232323232323232,
.cipher = 0x3232323232323232,
.plain = 0xDB71F2F904CE4467,
.encrypted = 0x3232323232323232
},

{
.key = 0x3333333333333333,
.cipher = 0x3333333333333333,
.plain = 0x19B6A607F49D7EBF,
.encrypted = 0x3333333333333333
},

{
.key = 0x3434343434343434,
.cipher = 0x3434343434343434,
.plain = 0x086DA2A46819B2EC,
.encrypted = 0x3434343434343434
},

{
.key = 0x3535353535353535,
.cipher = 0x3535353535353535,
.plain = 0xBFBEB4BB6C8BA8D3,
.encrypted = 0x3535353535353535
},

{
.key = 0x3636363636363636,
.cipher = 0x3636363636363636,
.plain = 0xC0EA975A16621073,
.encrypted = 0x3636363636363636
},

{
.key = 0x3737373737373737,
.cipher = 0x3737373737373737,
.plain = 0xB53D58A1CAD79864,
.encrypted = 0x3737373737373737
},

{
.key = 0x3838383838383838,
.cipher = 0x3838383838383838,
.plain = 0xB7F074CB09D21987,
.encrypted = 0x3838383838383838
},

{
.key = 0x3939393939393939,
.cipher = 0x3939393939393939,
.plain = 0xE6F6D6E5DCCAFBAF,
.encrypted = 0x3939393939393939
},

{
.key = 0x3A3A3A3A3A3A3A3A,
.cipher = 0x3A3A3A3A3A3A3A3A,
.plain = 0x428395367157DB18,
.encrypted = 0x3A3A3A3A3A3A3A3A
},

{
.key = 0x3B3B3B3B3B3B3B3B,
.cipher = 0x3B3B3B3B3B3B3B3B,
.plain = 0xB71F8389C32F928E,
.encrypted = 0x3B3B3B3B3B3B3B3B
},

{
.key = 0x3C3C3C3C3C3C3C3C,
.cipher = 0x3C3C3C3C3C3C3C3C,
.plain = 0x290DDC00BAFBF6C0,
.encrypted = 0x3C3C3C3C3C3C3C3C
},

{
.key = 0x3D3D3D3D3D3D3D3D,
.cipher = 0x3D3D3D3D3D3D3D3D,
.plain = 0x96F8EC19C7C00F69,
.encrypted = 0x3D3D3D3D3D3D3D3D
},

{
.key = 0x3E3E3E3E3E3E3E3E,
.cipher = 0x3E3E3E3E3E3E3E3E,
.plain = 0xE1E2B92BEC7B6EDA,
.encrypted = 0x3E3E3E3E3E3E3E3E
},

{
.key = 0x3F3F3F3F3F3F3F3F,
.cipher = 0x3F3F3F3F3F3F3F3F,
.plain = 0x4FCD12FF1A0F4828,
.encrypted = 0x3F3F3F3F3F3F3F3F
},

{
.key = 0x4040404040404040,
.cipher = 0x4040404040404040,
.plain = 0xFDA1AEAC4103BEC7,
.encrypted = 0x4040404040404040
},

{
.key = 0x4141414141414141,
.cipher = 0x4141414141414141,
.plain = 0xC023018BB50973DF,
.encrypted = 0x4141414141414141
},

{
.key = 0x4242424242424242,
.cipher = 0x4242424242424242,
.plain = 0x2F17AB3C4EF47CED,
.encrypted = 0x4242424242424242
},

{
.key = 0x4343434343434343,
.cipher = 0x4343434343434343,
.plain = 0x403E4F9726A43E2B,
.encrypted = 0x4343434343434343
},

{
.key = 0x4444444444444444,
.cipher = 0x4444444444444444,
.plain = 0x300FB94913B09D9F,
.encrypted = 0x4444444444444444
},

{
.key = 0x4545454545454545,
.cipher = 0x4545454545454545,
.plain = 0xCC3368EE3DD10A86,
.encrypted = 0x4545454545454545
},

{
.key = 0x4646464646464646,
.cipher = 0x4646464646464646,
.plain = 0x4047149B98541E84,
.encrypted = 0x4646464646464646
},

{
.key = 0x4747474747474747,
.cipher = 0x4747474747474747,
.plain = 0x6F50E18DA9045F21,
.encrypted = 0x4747474747474747
},

{
.key = 0x4848484848484848,
.cipher = 0x4848484848484848,
.plain = 0x8714D44CAC7D0D14,
.encrypted = 0x4848484848484848
},

{
.key = 0x4949494949494949,
.cipher = 0x4949494949494949,
.plain = 0x83829CFFC32CED9B,
.encrypted = 0x4949494949494949
},

{
.key = 0x4A4A4A4A4A4A4A4A,
.cipher = 0x4A4A4A4A4A4A4A4A,
.plain = 0x16044259F6FEEF2A,
.encrypted = 0x4A4A4A4A4A4A4A4A
},

{
.key = 0x4B4B4B4B4B4B4B4B,
.cipher = 0x4B4B4B4B4B4B4B4B,
.plain = 0xDAEB0CCC9F9C02A7,
.encrypted = 0x4B4B4B4B4B4B4B4B
},

{
.key = 0x4C4C4C4C4C4C4C4C,
.cipher = 0x4C4C4C4C4C4C4C4C,
.plain = 0x1F9442EA265CB749,
.encrypted = 0x4C4C4C4C4C4C4C4C
},

{
.key = 0x4D4D4D4D4D4D4D4D,
.cipher = 0x4D4D4D4D4D4D4D4D,
.plain = 0xE4911A6B657A86BE,
.encrypted = 0x4D4D4D4D4D4D4D4D
},

{
.key = 0x4E4E4E4E4E4E4E4E,
.cipher = 0x4E4E4E4E4E4E4E4E,
.plain = 0x67464D8D5A2822CF,
.encrypted = 0x4E4E4E4E4E4E4E4E
},

{
.key = 0x4F4F4F4F4F4F4F4F,
.cipher = 0x4F4F4F4F4F4F4F4F,
.plain = 0xC1419997381C7DA3,
.encrypted = 0x4F4F4F4F4F4F4F4F
},

{
.key = 0x5050505050505050,
.cipher = 0x5050505050505050,
.plain = 0x599A5CD62A06D027,
.encrypted = 0x5050505050505050
},

{
.key = 0x5151515151515151,
.cipher = 0x5151515151515151,
.plain = 0x88FD236C41B3BB51,
.encrypted = 0x5151515151515151
},

{
.key = 0x5252525252525252,
.cipher = 0x5252525252525252,
.plain = 0x41CC247560605B0B,
.encrypted = 0x5252525252525252
},

{
.key = 0x5353535353535353,
.cipher = 0x5353535353535353,
.plain = 0x0F91178929EF4AA1,
.encrypted = 0x5353535353535353
},

{
.key = 0x5454545454545454,
.cipher = 0x5454545454545454,
.plain = 0xDC644E7A6FAA6446,
.encrypted = 0x5454545454545454
},

{
.key = 0x5555555555555555,
.cipher = 0x5555555555555555,
.plain = 0x27BDEAC7848061C2,
.encrypted = 0x5555555555555555
},

{
.key = 0x5656565656565656,
.cipher = 0x5656565656565656,
.plain = 0x51115EC4EBDDE14E,
.encrypted = 0x5656565656565656
},

{
.key = 0x5757575757575757,
.cipher = 0x5757575757575757,
.plain = 0xA1731C55A4FB1B12,
.encrypted = 0x5757575757575757
},

{
.key = 0x5858585858585858,
.cipher = 0x5858585858585858,
.plain = 0x883D1CB568FA4AF6,
.encrypted = 0x5858585858585858
},

{
.key = 0x5959595959595959,
.cipher = 0x5959595959595959,
.plain = 0xEE21D431F34E89A5,
.encrypted = 0x5959595959595959
},

{
.key = 0x5A5A5A5A5A5A5A5A,
.cipher = 0x5A5A5A5A5A5A5A5A,
.plain = 0x8ED4FA5DF0B7BAA9,
.encrypted = 0x5A5A5A5A5A5A5A5A
},

{
.key = 0x5B5B5B5B5B5B5B5B,
.cipher = 0x5B5B5B5B5B5B5B5B,
.plain = 0x8AA3372D4A4CF54D,
.encrypted = 0x5B5B5B5B5B5B5B5B
},

{
.key = 0x5C5C5C5C5C5C5C5C,
.cipher = 0x5C5C5C5C5C5C5C5C,
.plain = 0x6E9D4FF9DE08AAD1,
.encrypted = 0x5C5C5C5C5C5C5C5C
},

{
.key = 0x5D5D5D5D5D5D5D5D,
.cipher = 0x5D5D5D5D5D5D5D5D,
.plain = 0x302DE41DFAE50C3E,
.encrypted = 0x5D5D5D5D5D5D5D5D
},

{
.key = 0x5E5E5E5E5E5E5E5E,
.cipher = 0x5E5E5E5E5E5E5E5E,
.plain = 0x15238624D6D73121,
.encrypted = 0x5E5E5E5E5E5E5E5E
},

{
.key = 0x5F5F5F5F5F5F5F5F,
.cipher = 0x5F5F5F5F5F5F5F5F,
.plain = 0x960ADA6F022E3019,
.encrypted = 0x5F5F5F5F5F5F5F5F
},

{
.key = 0x6060606060606060,
.cipher = 0x6060606060606060,
.plain = 0xCAF3211A707960D6,
.encrypted = 0x6060606060606060
},

{
.key = 0x6161616161616161,
.cipher = 0x6161616161616161,
.plain = 0xF7E458FA7081BE7D,
.encrypted = 0x6161616161616161
},

{
.key = 0x6262626262626262,
.cipher = 0x6262626262626262,
.plain = 0x5FAB0E843C6E5BA9,
.encrypted = 0x6262626262626262
},

{
.key = 0x6363636363636363,
.cipher = 0x6363636363636363,
.plain = 0x7CF40025EB32B66F,
.encrypted = 0x6363636363636363
},

{
.key = 0x6464646464646464,
.cipher = 0x6464646464646464,
.plain = 0x1D3FF19CA208D2B2,
.encrypted = 0x6464646464646464
},

{
.key = 0x6565656565656565,
.cipher = 0x6565656565656565,
.plain = 0xBDFBCA399EB932A0,
.encrypted = 0x6565656565656565
},

{
.key = 0x6666666666666666,
.cipher = 0x6666666666666666,
.plain = 0x29CE12AFEA960B70,
.encrypted = 0x6666666666666666
},

{
.key = 0x6767676767676767,
.cipher = 0x6767676767676767,
.plain = 0x82F8FB5140014B85,
.encrypted = 0x6767676767676767
},

{
.key = 0x6868686868686868,
.cipher = 0x6868686868686868,
.plain = 0x7B3C0F4E34F9D1E9,
.encrypted = 0x6868686868686868
},

{
.key = 0x6969696969696969,
.cipher = 0x6969696969696969,
.plain = 0x8F7B0EAD94E39A13,
.encrypted = 0x6969696969696969
},

{
.key = 0x6A6A6A6A6A6A6A6A,
.cipher = 0x6A6A6A6A6A6A6A6A,
.plain = 0x6D3F31C7778EAD8A,
.encrypted = 0x6A6A6A6A6A6A6A6A
},

{
.key = 0x6B6B6B6B6B6B6B6B,
.cipher = 0x6B6B6B6B6B6B6B6B,
.plain = 0x37B18B3906BAB3A8,
.encrypted = 0x6B6B6B6B6B6B6B6B
},

{
.key = 0x6C6C6C6C6C6C6C6C,
.cipher = 0x6C6C6C6C6C6C6C6C,
.plain = 0x12B4CB7A4CBE767B,
.encrypted = 0x6C6C6C6C6C6C6C6C
},

{
.key = 0x6D6D6D6D6D6D6D6D,
.cipher = 0x6D6D6D6D6D6D6D6D,
.plain = 0x2420B66A1055C0E9,
.encrypted = 0x6D6D6D6D6D6D6D6D
},

{
.key = 0x6E6E6E6E6E6E6E6E,
.cipher = 0x6E6E6E6E6E6E6E6E,
.plain = 0x7E8E816788C6D588,
.encrypted = 0x6E6E6E6E6E6E6E6E
},

{
.key = 0x6F6F6F6F6F6F6F6F,
.cipher = 0x6F6F6F6F6F6F6F6F,
.plain = 0xC24105E33E184FF6,
.encrypted = 0x6F6F6F6F6F6F6F6F
},

{
.key = 0x7070707070707070,
.cipher = 0x7070707070707070,
.plain = 0xE4A18C1C24EBFBB9,
.encrypted = 0x7070707070707070
},

{
.key = 0x7171717171717171,
.cipher = 0x7171717171717171,
.plain = 0x89BDBD3DE031EED6,
.encrypted = 0x7171717171717171
},

{
.key = 0x7272727272727272,
.cipher = 0x7272727272727272,
.plain = 0xDBB840AF153D42DC,
.encrypted = 0x7272727272727272
},

{
.key = 0x7373737373737373,
.cipher = 0x7373737373737373,
.plain = 0x5198BB48B85D9073,
.encrypted = 0x7373737373737373
},

{
.key = 0x7474747474747474,
.cipher = 0x7474747474747474,
.plain = 0xEF91577024209D96,
.encrypted = 0x7474747474747474
},

{
.key = 0x7575757575757575,
.cipher = 0x7575757575757575,
.plain = 0x862D09602D08F4AF,
.encrypted = 0x7575757575757575
},

{
.key = 0x7676767676767676,
.cipher = 0x7676767676767676,
.plain = 0xDF8FDD3DA8BE381C,
.encrypted = 0x7676767676767676
},

{
.key = 0x7777777777777777,
.cipher = 0x7777777777777777,
.plain = 0xF4FA92CAF1EA65C8,
.encrypted = 0x7777777777777777
},

{
.key = 0x7878787878787878,
.cipher = 0x7878787878787878,
.plain = 0x6C51D39A736AB06E,
.encrypted = 0x7878787878787878
},

{
.key = 0x7979797979797979,
.cipher = 0x7979797979797979,
.plain = 0xCA78FA0F8940CDB6,
.encrypted = 0x7979797979797979
},

{
.key = 0x7A7A7A7A7A7A7A7A,
.cipher = 0x7A7A7A7A7A7A7A7A,
.plain = 0xE32531D4F4783A94,
.encrypted = 0x7A7A7A7A7A7A7A7A
},

{
.key = 0x7B7B7B7B7B7B7B7B,
.cipher = 0x7B7B7B7B7B7B7B7B,
.plain = 0xC983F15CAE1DEB86,
.encrypted = 0x7B7B7B7B7B7B7B7B
},

{
.key = 0x7C7C7C7C7C7C7C7C,
.cipher = 0x7C7C7C7C7C7C7C7C,
.plain = 0xF8895BF6515436F3,
.encrypted = 0x7C7C7C7C7C7C7C7C
},

{
.key = 0x7D7D7D7D7D7D7D7D,
.cipher = 0x7D7D7D7D7D7D7D7D,
.plain = 0x0B679E5008B5B69B,
.encrypted = 0x7D7D7D7D7D7D7D7D
},

{
.key = 0x7E7E7E7E7E7E7E7E,
.cipher = 0x7E7E7E7E7E7E7E7E,
.plain = 0x909D89361F819432,
.encrypted = 0x7E7E7E7E7E7E7E7E
},

{
.key = 0x7F7F7F7F7F7F7F7F,
.cipher = 0x7F7F7F7F7F7F7F7F,
.plain = 0xC8FCD27001B95D10,
.encrypted = 0x7F7F7F7F7F7F7F7F
},

{
.key = 0x8080808080808080,
.cipher = 0x8080808080808080,
.plain = 0x37032D8FFE46A2EF,
.encrypted = 0x8080808080808080
},

{
.key = 0x8181818181818181,
.cipher = 0x8181818181818181,
.plain = 0x6F6276C9E07E6BCD,
.encrypted = 0x8181818181818181
},

{
.key = 0x8282828282828282,
.cipher = 0x8282828282828282,
.plain = 0xF49861AFF74A4964,
.encrypted = 0x8282828282828282
},

{
.key = 0x8383838383838383,
.cipher = 0x8383838383838383,
.plain = 0x0776A409AEABC90C,
.encrypted = 0x8383838383838383
},

{
.key = 0x8484848484848484,
.cipher = 0x8484848484848484,
.plain = 0x367C0EA351E21479,
.encrypted = 0x8484848484848484
},

{
.key = 0x8585858585858585,
.cipher = 0x8585858585858585,
.plain = 0x1CDACE2B0B87C56B,
.encrypted = 0x8585858585858585
},

{
.key = 0x8686868686868686,
.cipher = 0x8686868686868686,
.plain = 0x358705F076BF3249,
.encrypted = 0x8686868686868686
},

{
.key = 0x8787878787878787,
.cipher = 0x8787878787878787,
.plain = 0x93AE2C658C954F91,
.encrypted = 0x8787878787878787
},

{
.key = 0x8888888888888888,
.cipher = 0x8888888888888888,
.plain = 0x0B056D350E159A37,
.encrypted = 0x8888888888888888
},

{
.key = 0x8989898989898989,
.cipher = 0x8989898989898989,
.plain = 0x207022C25741C7E3,
.encrypted = 0x8989898989898989
},

{
.key = 0x8A8A8A8A8A8A8A8A,
.cipher = 0x8A8A8A8A8A8A8A8A,
.plain = 0x79D2F69FD2F70B50,
.encrypted = 0x8A8A8A8A8A8A8A8A
},

{
.key = 0x8B8B8B8B8B8B8B8B,
.cipher = 0x8B8B8B8B8B8B8B8B,
.plain = 0x106EA88FDBDF6269,
.encrypted = 0x8B8B8B8B8B8B8B8B
},

{
.key = 0x8C8C8C8C8C8C8C8C,
.cipher = 0x8C8C8C8C8C8C8C8C,
.plain = 0xAE6744B747A26F8C,
.encrypted = 0x8C8C8C8C8C8C8C8C
},

{
.key = 0x8D8D8D8D8D8D8D8D,
.cipher = 0x8D8D8D8D8D8D8D8D,
.plain = 0x2447BF50EAC2BD23,
.encrypted = 0x8D8D8D8D8D8D8D8D
},

{
.key = 0x8E8E8E8E8E8E8E8E,
.cipher = 0x8E8E8E8E8E8E8E8E,
.plain = 0x764242C21FCE1129,
.encrypted = 0x8E8E8E8E8E8E8E8E
},

{
.key = 0x8F8F8F8F8F8F8F8F,
.cipher = 0x8F8F8F8F8F8F8F8F,
.plain = 0x1B5E73E3DB140446,
.encrypted = 0x8F8F8F8F8F8F8F8F
},

{
.key = 0x9090909090909090,
.cipher = 0x9090909090909090,
.plain = 0x3DBEFA1CC1E7B009,
.encrypted = 0x9090909090909090
},

{
.key = 0x9191919191919191,
.cipher = 0x9191919191919191,
.plain = 0x81717E9877392A77,
.encrypted = 0x9191919191919191
},

{
.key = 0x9292929292929292,
.cipher = 0x9292929292929292,
.plain = 0xDBDF4995EFAA3F16,
.encrypted = 0x9292929292929292
},

{
.key = 0x9393939393939393,
.cipher = 0x9393939393939393,
.plain = 0xED4B3485B3418984,
.encrypted = 0x9393939393939393
},

{
.key = 0x9494949494949494,
.cipher = 0x9494949494949494,
.plain = 0xC84E74C6F9454C57,
.encrypted = 0x9494949494949494
},

{
.key = 0x9595959595959595,
.cipher = 0x9595959595959595,
.plain = 0x92C0CE3888715275,
.encrypted = 0x9595959595959595
},

{
.key = 0x9696969696969696,
.cipher = 0x9696969696969696,
.plain = 0x7084F1526B1C65EC,
.encrypted = 0x9696969696969696
},

{
.key = 0x9797979797979797,
.cipher = 0x9797979797979797,
.plain = 0x84C3F0B1CB062E16,
.encrypted = 0x9797979797979797
},

{
.key = 0x9898989898989898,
.cipher = 0x9898989898989898,
.plain = 0x7D0704AEBFFEB47A,
.encrypted = 0x9898989898989898
},

{
.key = 0x9999999999999999,
.cipher = 0x9999999999999999,
.plain = 0xD631ED501569F48F,
.encrypted = 0x9999999999999999
},

{
.key = 0x9A9A9A9A9A9A9A9A,
.cipher = 0x9A9A9A9A9A9A9A9A,
.plain = 0x420435C66146CD5F,
.encrypted = 0x9A9A9A9A9A9A9A9A
},

{
.key = 0x9B9B9B9B9B9B9B9B,
.cipher = 0x9B9B9B9B9B9B9B9B,
.plain = 0xE2C00E635DF72D4D,
.encrypted = 0x9B9B9B9B9B9B9B9B
},

{
.key = 0x9C9C9C9C9C9C9C9C,
.cipher = 0x9C9C9C9C9C9C9C9C,
.plain = 0x830BFFDA14CD4990,
.encrypted = 0x9C9C9C9C9C9C9C9C
},

{
.key = 0x9D9D9D9D9D9D9D9D,
.cipher = 0x9D9D9D9D9D9D9D9D,
.plain = 0xA054F17BC391A456,
.encrypted = 0x9D9D9D9D9D9D9D9D
},

{
.key = 0x9E9E9E9E9E9E9E9E,
.cipher = 0x9E9E9E9E9E9E9E9E,
.plain = 0x081BA7058F7E4182,
.encrypted = 0x9E9E9E9E9E9E9E9E
},

{
.key = 0x9F9F9F9F9F9F9F9F,
.cipher = 0x9F9F9F9F9F9F9F9F,
.plain = 0x350CDEE58F869F29,
.encrypted = 0x9F9F9F9F9F9F9F9F
},

{
.key = 0xA0A0A0A0A0A0A0A0,
.cipher = 0xA0A0A0A0A0A0A0A0,
.plain = 0x69F52590FDD1CFE6,
.encrypted = 0xA0A0A0A0A0A0A0A0
},

{
.key = 0xA1A1A1A1A1A1A1A1,
.cipher = 0xA1A1A1A1A1A1A1A1,
.plain = 0xEADC79DB2928CEDE,
.encrypted = 0xA1A1A1A1A1A1A1A1
},

{
.key = 0xA2A2A2A2A2A2A2A2,
.cipher = 0xA2A2A2A2A2A2A2A2,
.plain = 0xCFD21BE2051AF3C1,
.encrypted = 0xA2A2A2A2A2A2A2A2
},

{
.key = 0xA3A3A3A3A3A3A3A3,
.cipher = 0xA3A3A3A3A3A3A3A3,
.plain = 0x9162B00621F7552E,
.encrypted = 0xA3A3A3A3A3A3A3A3
},

{
.key = 0xA4A4A4A4A4A4A4A4,
.cipher = 0xA4A4A4A4A4A4A4A4,
.plain = 0x755CC8D2B5B30AB2,
.encrypted = 0xA4A4A4A4A4A4A4A4
},

{
.key = 0xA5A5A5A5A5A5A5A5,
.cipher = 0xA5A5A5A5A5A5A5A5,
.plain = 0x712B05A20F484556,
.encrypted = 0xA5A5A5A5A5A5A5A5
},

{
.key = 0xA6A6A6A6A6A6A6A6,
.cipher = 0xA6A6A6A6A6A6A6A6,
.plain = 0x11DE2BCE0CB1765A,
.encrypted = 0xA6A6A6A6A6A6A6A6
},

{
.key = 0xA7A7A7A7A7A7A7A7,
.cipher = 0xA7A7A7A7A7A7A7A7,
.plain = 0x77C2E34A9705B509,
.encrypted = 0xA7A7A7A7A7A7A7A7
},

{
.key = 0xA8A8A8A8A8A8A8A8,
.cipher = 0xA8A8A8A8A8A8A8A8,
.plain = 0x5E8CE3AA5B04E4ED,
.encrypted = 0xA8A8A8A8A8A8A8A8
},

{
.key = 0xA9A9A9A9A9A9A9A9,
.cipher = 0xA9A9A9A9A9A9A9A9,
.plain = 0xAEEEA13B14221EB1,
.encrypted = 0xA9A9A9A9A9A9A9A9
},

{
.key = 0xAAAAAAAAAAAAAAAA,
.cipher = 0xAAAAAAAAAAAAAAAA,
.plain = 0xD84215387B7F9E3D,
.encrypted = 0xAAAAAAAAAAAAAAAA
},

{
.key = 0xABABABABABABABAB,
.cipher = 0xABABABABABABABAB,
.plain = 0x239BB18590559BB9,
.encrypted = 0xABABABABABABABAB
},

{
.key = 0xACACACACACACACAC,
.cipher = 0xACACACACACACACAC,
.plain = 0xF06EE876D610B55E,
.encrypted = 0xACACACACACACACAC
},

{
.key = 0xADADADADADADADAD,
.cipher = 0xADADADADADADADAD,
.plain = 0xBE33DB8A9F9FA4F4,
.encrypted = 0xADADADADADADADAD
},

{
.key = 0xAEAEAEAEAEAEAEAE,
.cipher = 0xAEAEAEAEAEAEAEAE,
.plain = 0x7702DC93BE4C44AE,
.encrypted = 0xAEAEAEAEAEAEAEAE
},

{
.key = 0xAFAFAFAFAFAFAFAF,
.cipher = 0xAFAFAFAFAFAFAFAF,
.plain = 0xA665A329D5F92FD8,
.encrypted = 0xAFAFAFAFAFAFAFAF
},

{
.key = 0xB0B0B0B0B0B0B0B0,
.cipher = 0xB0B0B0B0B0B0B0B0,
.plain = 0x3EBE6668C7E3825C,
.encrypted = 0xB0B0B0B0B0B0B0B0
},

{
.key = 0xB1B1B1B1B1B1B1B1,
.cipher = 0xB1B1B1B1B1B1B1B1,
.plain = 0x98B9B272A5D7DD30,
.encrypted = 0xB1B1B1B1B1B1B1B1
},

{
.key = 0xB2B2B2B2B2B2B2B2,
.cipher = 0xB2B2B2B2B2B2B2B2,
.plain = 0x1B6EE5949A857941,
.encrypted = 0xB2B2B2B2B2B2B2B2
},

{
.key = 0xB3B3B3B3B3B3B3B3,
.cipher = 0xB3B3B3B3B3B3B3B3,
.plain = 0xE06BBD15D9A348B6,
.encrypted = 0xB3B3B3B3B3B3B3B3
},

{
.key = 0xB4B4B4B4B4B4B4B4,
.cipher = 0xB4B4B4B4B4B4B4B4,
.plain = 0x2514F3336063FD58,
.encrypted = 0xB4B4B4B4B4B4B4B4
},

{
.key = 0xB5B5B5B5B5B5B5B5,
.cipher = 0xB5B5B5B5B5B5B5B5,
.plain = 0xE9FBBDA6090110D5,
.encrypted = 0xB5B5B5B5B5B5B5B5
},

{
.key = 0xB6B6B6B6B6B6B6B6,
.cipher = 0xB6B6B6B6B6B6B6B6,
.plain = 0x7C7D63003CD31264,
.encrypted = 0xB6B6B6B6B6B6B6B6
},

{
.key = 0xB7B7B7B7B7B7B7B7,
.cipher = 0xB7B7B7B7B7B7B7B7,
.plain = 0x78EB2BB35382F2EB,
.encrypted = 0xB7B7B7B7B7B7B7B7
},

{
	.key = 0xB8B8B8B8B8B8B8B8,
		.cipher = 0xB8B8B8B8B8B8B8B8,
		.plain = 0x90AF1E7256FBA0DE,
		.encrypted = 0xB8B8B8B8B8B8B8B8
},

{
	.key = 0xB9B9B9B9B9B9B9B9,
		.cipher = 0xB9B9B9B9B9B9B9B9,
		.plain = 0xBFB8EB6467ABE17B,
		.encrypted = 0xB9B9B9B9B9B9B9B9
},

{
	.key = 0xBABABABABABABABA,
		.cipher = 0xBABABABABABABABA,
		.plain = 0x33CC9711C22EF579,
		.encrypted = 0xBABABABABABABABA
},

{
	.key = 0xBBBBBBBBBBBBBBBB,
		.cipher = 0xBBBBBBBBBBBBBBBB,
		.plain = 0xCFF046B6EC4F6260,
		.encrypted = 0xBBBBBBBBBBBBBBBB
},

{
	.key = 0xBCBCBCBCBCBCBCBC,
		.cipher = 0xBCBCBCBCBCBCBCBC,
		.plain = 0xBFC1B068D95BC1D4,
		.encrypted = 0xBCBCBCBCBCBCBCBC
},

{
	.key = 0xBDBDBDBDBDBDBDBD,
		.cipher = 0xBDBDBDBDBDBDBDBD,
		.plain = 0xD0E854C3B10B8312,
		.encrypted = 0xBDBDBDBDBDBDBDBD
},

{
	.key = 0xBEBEBEBEBEBEBEBE,
		.cipher = 0xBEBEBEBEBEBEBEBE,
		.plain = 0x3FDCFE744AF68C20,
		.encrypted = 0xBEBEBEBEBEBEBEBE
},

{
	.key = 0xBFBFBFBFBFBFBFBF,
		.cipher = 0xBFBFBFBFBFBFBFBF,
		.plain = 0x025E5153BEFC4138,
		.encrypted = 0xBFBFBFBFBFBFBFBF
},

{
	.key = 0xC0C0C0C0C0C0C0C0,
		.cipher = 0xC0C0C0C0C0C0C0C0,
		.plain = 0xB032ED00E5F0B7D7,
		.encrypted = 0xC0C0C0C0C0C0C0C0
},

{
	.key = 0xC1C1C1C1C1C1C1C1,
		.cipher = 0xC1C1C1C1C1C1C1C1,
		.plain = 0x1E1D46D413849125,
		.encrypted = 0xC1C1C1C1C1C1C1C1
},

{
	.key = 0xC2C2C2C2C2C2C2C2,
		.cipher = 0xC2C2C2C2C2C2C2C2,
		.plain = 0x690713E6383FF096,
		.encrypted = 0xC2C2C2C2C2C2C2C2
},

{
	.key = 0xC3C3C3C3C3C3C3C3,
		.cipher = 0xC3C3C3C3C3C3C3C3,
		.plain = 0xD6F223FF4504093F,
		.encrypted = 0xC3C3C3C3C3C3C3C3
},

{
	.key = 0xC4C4C4C4C4C4C4C4,
		.cipher = 0xC4C4C4C4C4C4C4C4,
		.plain = 0x48E07C763CD06D71,
		.encrypted = 0xC4C4C4C4C4C4C4C4
},

{
	.key = 0xC5C5C5C5C5C5C5C5,
		.cipher = 0xC5C5C5C5C5C5C5C5,
		.plain = 0xBD7C6AC98EA824E7,
		.encrypted = 0xC5C5C5C5C5C5C5C5
},

{
	.key = 0xC6C6C6C6C6C6C6C6,
		.cipher = 0xC6C6C6C6C6C6C6C6,
		.plain = 0x1909291A23350450,
		.encrypted = 0xC6C6C6C6C6C6C6C6
},

{
	.key = 0xC7C7C7C7C7C7C7C7,
		.cipher = 0xC7C7C7C7C7C7C7C7,
		.plain = 0x480F8B34F62DE678,
		.encrypted = 0xC7C7C7C7C7C7C7C7
},

{
	.key = 0xC8C8C8C8C8C8C8C8,
		.cipher = 0xC8C8C8C8C8C8C8C8,
		.plain = 0x4AC2A75E3528679B,
		.encrypted = 0xC8C8C8C8C8C8C8C8
},

{
	.key = 0xC9C9C9C9C9C9C9C9,
		.cipher = 0xC9C9C9C9C9C9C9C9,
		.plain = 0x3F1568A5E99DEF8C,
		.encrypted = 0xC9C9C9C9C9C9C9C9
},

{
	.key = 0xCACACACACACACACA,
		.cipher = 0xCACACACACACACACA,
		.plain = 0x40414B449374572C,
		.encrypted = 0xCACACACACACACACA
},

{
	.key = 0xCBCBCBCBCBCBCBCB,
		.cipher = 0xCBCBCBCBCBCBCBCB,
		.plain = 0xF7925D5B97E64D13,
		.encrypted = 0xCBCBCBCBCBCBCBCB
},

{
	.key = 0xCCCCCCCCCCCCCCCC,
		.cipher = 0xCCCCCCCCCCCCCCCC,
		.plain = 0xE64959F80B628140,
		.encrypted = 0xCCCCCCCCCCCCCCCC
},

{
	.key = 0xCDCDCDCDCDCDCDCD,
		.cipher = 0xCDCDCDCDCDCDCDCD,
		.plain = 0x248E0D06FB31BB98,
		.encrypted = 0xCDCDCDCDCDCDCDCD
},

{
	.key = 0xCECECECECECECECE,
		.cipher = 0xCECECECECECECECE,
		.plain = 0x92F58133675FE659,
		.encrypted = 0xCECECECECECECECE
},

{
	.key = 0xCFCFCFCFCFCFCFCF,
		.cipher = 0xCFCFCFCFCFCFCFCF,
		.plain = 0xCCA53A1AB55B3A05,
		.encrypted = 0xCFCFCFCFCFCFCFCF
},

{
	.key = 0xD0D0D0D0D0D0D0D0,
		.cipher = 0xD0D0D0D0D0D0D0D0,
		.plain = 0x8066E3CA18E0726A,
		.encrypted = 0xD0D0D0D0D0D0D0D0
},

{
	.key = 0xD1D1D1D1D1D1D1D1,
		.cipher = 0xD1D1D1D1D1D1D1D1,
		.plain = 0x9A610E9161003E92,
		.encrypted = 0xD1D1D1D1D1D1D1D1
},

{
	.key = 0xD2D2D2D2D2D2D2D2,
		.cipher = 0xD2D2D2D2D2D2D2D2,
		.plain = 0x9F10AB312F9C1153,
		.encrypted = 0xD2D2D2D2D2D2D2D2
},

{
	.key = 0xD3D3D3D3D3D3D3D3,
		.cipher = 0xD3D3D3D3D3D3D3D3,
		.plain = 0x5E55536492C254F5,
		.encrypted = 0xD3D3D3D3D3D3D3D3
},

{
	.key = 0xD4D4D4D4D4D4D4D4,
		.cipher = 0xD4D4D4D4D4D4D4D4,
		.plain = 0x2EC41BB94EAC683F,
		.encrypted = 0xD4D4D4D4D4D4D4D4
},

{
	.key = 0xD5D5D5D5D5D5D5D5,
		.cipher = 0xD5D5D5D5D5D5D5D5,
		.plain = 0xE6264B3CFA54A53B,
		.encrypted = 0xD5D5D5D5D5D5D5D5
},

{
	.key = 0xD6D6D6D6D6D6D6D6,
		.cipher = 0xD6D6D6D6D6D6D6D6,
		.plain = 0x9B0FE80CA5C0AF2E,
		.encrypted = 0xD6D6D6D6D6D6D6D6
},

{
	.key = 0xD7D7D7D7D7D7D7D7,
		.cipher = 0xD7D7D7D7D7D7D7D7,
		.plain = 0x9F99107A00E075B9,
		.encrypted = 0xD7D7D7D7D7D7D7D7
},

{
	.key = 0xD8D8D8D8D8D8D8D8,
		.cipher = 0xD8D8D8D8D8D8D8D8,
		.plain = 0xEE5A79323EA0B49D,
		.encrypted = 0xD8D8D8D8D8D8D8D8
},

{
	.key = 0xD9D9D9D9D9D9D9D9,
		.cipher = 0xD9D9D9D9D9D9D9D9,
		.plain = 0x57D818D32E7BAAA1,
		.encrypted = 0xD9D9D9D9D9D9D9D9
},

{
	.key = 0xDADADADADADADADA,
		.cipher = 0xDADADADADADADADA,
		.plain = 0x2372BA28AE804A73,
		.encrypted = 0xDADADADADADADADA
},

{
	.key = 0xDBDBDBDBDBDBDBDB,
		.cipher = 0xDBDBDBDBDBDBDBDB,
		.plain = 0x370FD75C119F4D76,
		.encrypted = 0xDBDBDBDBDBDBDBDB
},

{
	.key = 0xDCDCDCDCDCDCDCDC,
		.cipher = 0xDCDCDCDCDCDCDCDC,
		.plain = 0x70ADE48AB7C5F46B,
		.encrypted = 0xDCDCDCDCDCDCDCDC
},

{
	.key = 0xDDDDDDDDDDDDDDDD,
		.cipher = 0xDDDDDDDDDDDDDDDD,
		.plain = 0x2EFA06CFEF4C490A,
		.encrypted = 0xDDDDDDDDDDDDDDDD
},

{
	.key = 0xDEDEDEDEDEDEDEDE,
		.cipher = 0xDEDEDEDEDEDEDEDE,
		.plain = 0x57F4D40141EF5B25,
		.encrypted = 0xDEDEDEDEDEDEDEDE
},

{
	.key = 0xDFDFDFDFDFDFDFDF,
		.cipher = 0xDFDFDFDFDFDFDFDF,
		.plain = 0x6F8C38686FCF9082,
		.encrypted = 0xDFDFDFDFDFDFDFDF
},

{
	.key = 0xE0E0E0E0E0E0E0E0,
		.cipher = 0xE0E0E0E0E0E0E0E0,
		.plain = 0x9E4EBA2683B6EADC,
		.encrypted = 0xE0E0E0E0E0E0E0E0
},

{
	.key = 0xE1E1E1E1E1E1E1E1,
		.cipher = 0xE1E1E1E1E1E1E1E1,
		.plain = 0x37FBF97B5DF82E4A,
		.encrypted = 0xE1E1E1E1E1E1E1E1
},

{
	.key = 0xE2E2E2E2E2E2E2E2,
		.cipher = 0xE2E2E2E2E2E2E2E2,
		.plain = 0xF8605C8127F45F9B,
		.encrypted = 0xE2E2E2E2E2E2E2E2
},

{
	.key = 0xE3E3E3E3E3E3E3E3,
		.cipher = 0xE3E3E3E3E3E3E3E3,
		.plain = 0xCFE89CC047E6836A,
		.encrypted = 0xE3E3E3E3E3E3E3E3
},

{
	.key = 0xE4E4E4E4E4E4E4E4,
		.cipher = 0xE4E4E4E4E4E4E4E4,
		.plain = 0x7060B673459206F7,
		.encrypted = 0xE4E4E4E4E4E4E4E4
},

{
	.key = 0xE5E5E5E5E5E5E5E5,
		.cipher = 0xE5E5E5E5E5E5E5E5,
		.plain = 0x49D3014B922E7A88,
		.encrypted = 0xE5E5E5E5E5E5E5E5
},

{
	.key = 0xE6E6E6E6E6E6E6E6,
		.cipher = 0xE6E6E6E6E6E6E6E6,
		.plain = 0x638146A34E7DDCC1,
		.encrypted = 0xE6E6E6E6E6E6E6E6
},

{
	.key = 0xE7E7E7E7E7E7E7E7,
		.cipher = 0xE7E7E7E7E7E7E7E7,
		.plain = 0xD106D7199C6791E3,
		.encrypted = 0xE7E7E7E7E7E7E7E7
},

{
	.key = 0xE8E8E8E8E8E8E8E8,
		.cipher = 0xE8E8E8E8E8E8E8E8,
		.plain = 0x9B00500449F74FFD,
		.encrypted = 0xE8E8E8E8E8E8E8E8
},

{
	.key = 0xE9E9E9E9E9E9E9E9,
		.cipher = 0xE9E9E9E9E9E9E9E9,
		.plain = 0xAAF04E5AAF85B612,
		.encrypted = 0xE9E9E9E9E9E9E9E9
},

{
	.key = 0xEAEAEAEAEAEAEAEA,
		.cipher = 0xEAEAEAEAEAEAEAEA,
		.plain = 0xAC4B251F989E005E,
		.encrypted = 0xEAEAEAEAEAEAEAEA
},

{
	.key = 0xEBEBEBEBEBEBEBEB,
		.cipher = 0xEBEBEBEBEBEBEBEB,
		.plain = 0xE1A6F9B0015E6E10,
		.encrypted = 0xEBEBEBEBEBEBEBEB
},

{
	.key = 0xECECECECECECECEC,
		.cipher = 0xECECECECECECECEC,
		.plain = 0xE288627548617610,
		.encrypted = 0xECECECECECECECEC
},

{
	.key = 0xEDEDEDEDEDEDEDED,
		.cipher = 0xEDEDEDEDEDEDEDED,
		.plain = 0x5D0975698BF1C0D2,
		.encrypted = 0xEDEDEDEDEDEDEDED
},

{
	.key = 0xEEEEEEEEEEEEEEEE,
		.cipher = 0xEEEEEEEEEEEEEEEE,
		.plain = 0xDC84DCFB3C6C2C53,
		.encrypted = 0xEEEEEEEEEEEEEEEE
},

{
	.key = 0xEFEFEFEFEFEFEFEF,
		.cipher = 0xEFEFEFEFEFEFEFEF,
		.plain = 0x4C89378B1906782F,
		.encrypted = 0xEFEFEFEFEFEFEFEF
},

{
	.key = 0xF0F0F0F0F0F0F0F0,
		.cipher = 0xF0F0F0F0F0F0F0F0,
		.plain = 0xA8FA85D47AC98412,
		.encrypted = 0xF0F0F0F0F0F0F0F0
},

{
	.key = 0xF1F1F1F1F1F1F1F1,
		.cipher = 0xF1F1F1F1F1F1F1F1,
		.plain = 0x0E123A4E06709CEC,
		.encrypted = 0xF1F1F1F1F1F1F1F1
},

{
	.key = 0xF2F2F2F2F2F2F2F2,
		.cipher = 0xF2F2F2F2F2F2F2F2,
		.plain = 0xEB629B6D5F27F611,
		.encrypted = 0xF2F2F2F2F2F2F2F2
},

{
	.key = 0xF3F3F3F3F3F3F3F3,
		.cipher = 0xF3F3F3F3F3F3F3F3,
		.plain = 0x6066A70C1D898158,
		.encrypted = 0xF3F3F3F3F3F3F3F3
},

{
	.key = 0xF4F4F4F4F4F4F4F4,
		.cipher = 0xF4F4F4F4F4F4F4F4,
		.plain = 0x4A52E373B669A335,
		.encrypted = 0xF4F4F4F4F4F4F4F4
},

{
	.key = 0xF5F5F5F5F5F5F5F5,
		.cipher = 0xF5F5F5F5F5F5F5F5,
		.plain = 0x3197EEEE45C484EE,
		.encrypted = 0xF5F5F5F5F5F5F5F5
},

{
	.key = 0xF6F6F6F6F6F6F6F6,
		.cipher = 0xF6F6F6F6F6F6F6F6,
		.plain = 0xAEEF1A655138CCA4,
		.encrypted = 0xF6F6F6F6F6F6F6F6
},

{
	.key = 0xF7F7F7F7F7F7F7F7,
		.cipher = 0xF7F7F7F7F7F7F7F7,
		.plain = 0x26CD7B8BBA25B027,
		.encrypted = 0xF7F7F7F7F7F7F7F7
},

{
	.key = 0xF8F8F8F8F8F8F8F8,
		.cipher = 0xF8F8F8F8F8F8F8F8,
		.plain = 0x7200565F4D0DAB74,
		.encrypted = 0xF8F8F8F8F8F8F8F8
},

{
	.key = 0xF9F9F9F9F9F9F9F9,
		.cipher = 0xF9F9F9F9F9F9F9F9,
		.plain = 0x5510622EE218BAB9,
		.encrypted = 0xF9F9F9F9F9F9F9F9
},

{
	.key = 0xFAFAFAFAFAFAFAFA,
		.cipher = 0xFAFAFAFAFAFAFAFA,
		.plain = 0xDA9896ABAD6FCE34,
		.encrypted = 0xFAFAFAFAFAFAFAFA
},

{
	.key = 0xFBFBFBFBFBFBFBFB,
		.cipher = 0xFBFBFBFBFBFBFBFB,
		.plain = 0x766E3F3B730F507E,
		.encrypted = 0xFBFBFBFBFBFBFBFB
},

{
	.key = 0xFCFCFCFCFCFCFCFC,
		.cipher = 0xFCFCFCFCFCFCFCFC,
		.plain = 0x6E738510076C52AE,
		.encrypted = 0xFCFCFCFCFCFCFCFC
},

{
	.key = 0xFDFDFDFDFDFDFDFD,
		.cipher = 0xFDFDFDFDFDFDFDFD,
		.plain = 0x0F6059C33205D452,
		.encrypted = 0xFDFDFDFDFDFDFDFD
},

{
	.key = 0xFEFEFEFEFEFEFEFE,
		.cipher = 0xFEFEFEFEFEFEFEFE,
		.plain = 0x66B2B23EA84693AD,
		.encrypted = 0xFEFEFEFEFEFEFEFE
},

{
	.key = 0xFFFFFFFFFFFFFFFF,
		.cipher = 0xFFFFFFFFFFFFFFFF,
		.plain = 0x7359B2163E4EDC58,
		.encrypted = 0xFFFFFFFFFFFFFFFF
},

{
	.key = 0x0001020304050607,
		.cipher = 0x0011223344556677,
		.plain = 0x41AD068548809D02,
		.encrypted = 0x0011223344556677
},

{
	.key = 0x2BD6459F82C5B300,
		.cipher = 0xEA024714AD5C4D84,
		.plain = 0xB10F843097A0F932,
		.encrypted = 0xEA024714AD5C4D84
}
};

void DataEncryptionStandardConsoleDebugTest() {
	size_t numberTests = sizeof(DES_test_vector) / sizeof(*DES_test_vector);
	size_t lengthTest = 8;
	size_t i;
	for (i = 0; i < numberTests / 2; i++) {
		uint64_t key = DES_test_vector[i].key;
		uint64_t plain = DES_test_vector[i].plain;
		uint64_t cipher = DES_test_vector[i].cipher;
		uint64_t decrypted = DES_test_vector[i].decrypted;
		uint64_t encrypted = DES_test_vector[i].encrypted;
		uint64_t iterated_1000_times = DES_test_vector[i].iterated_1000_times;
		uint64_t iterated_100_times = DES_test_vector[i].iterated_100_times;
		struct DESinfo info = DataEncryptionStandardEncrypt((uint8_t*)&plain, lengthTest, key);
		if (info.blocks[0] == cipher) {
			DataEncryptionStandardDecrypt(&info, key);
			if (info.blocks[0] == decrypted) {
				printf("%d %s", i, "SUCCESS\n");
			}
			else
				printf("%d %s", i, "FAILED: Decrypt\n");
		}
		else
			printf("%d %s", i, "FAILED: Encrypt\n");
		free(info.blocks);
	}

	//for (; i < numberTests; i++) {
	//	struct DESinfo info;
	//	uint64_t key = DES_test_vector[i].key;
	//	uint64_t cipher = DES_test_vector[i].cipher;
	//	uint64_t encrypted = DES_test_vector[i].encrypted;
	//	uint64_t decrypted = DES_test_vector[i].decrypted;
	//	info.blocks = &cipher;
	//	info.numberBlocks = 1;
	//	DataEncryptionStandardDecrypt(&info, key);
	//	info = DataEncryptionStandardEncrypt(&info.blocks[0], lengthTest, key);

	//	if (info.blocks[0] == decrypted) {
	//		printf("%d %s", i, "SUCCESS\n");
	//	}
	//	else {
	//		printf("%d %s", i, "FAILED\n");
	//	}
	//	free(info.blocks);
	//}
}