#include "main.h"

std::vector<std::vector<double>> RightPaths::curveLeft = {
        {0},
        {0.0291},
        {0.0688},
        {0.1133},
        {0.1574},
        {0.2015},
        {0.2456},
        {0.2897},
        {0.3337},
        {0.3784},
        {0.4219},
        {0.4662},
        {0.5101},
        {0.554},
        {0.5983},
        {0.6416},
        {0.6861},
        {0.7298},
        {0.7737},
        {0.818},
        {0.8611},
        {0.9056},
        {0.949},
        {0.9931},
        {1.0361},
        {1.0809},
        {1.1234},
        {1.1682},
        {1.2107},
        {1.2549},
        {1.2984},
        {1.3419},
        {1.385},
        {1.4288},
        {1.4717},
        {1.5153},
        {1.5589},
        {1.6015},
        {1.645},
        {1.6881},
        {1.7311},
        {1.7745},
        {1.8167},
        {1.8604},
        {1.9029},
        {1.9461},
        {1.9885},
        {2.0313},
        {2.0743},
        {2.1169},
        {2.1591},
        {2.202},
        {2.2445},
        {2.2869},
        {2.3293},
        {2.3713},
        {2.4143},
        {2.4565},
        {2.498},
        {2.5409},
        {2.5831},
        {2.6244},
        {2.6676},
        {2.7088},
        {2.7512},
        {2.7932},
        {2.8351},
        {2.8771},
        {2.919},
        {2.9612},
        {3.0028},
        {3.0446},
        {3.0865},
        {3.1291},
        {3.1702},
        {3.2125},
        {3.254},
        {3.2966},
        {3.3382},
        {3.3802},
        {3.4221},
        {3.4645},
        {3.5066},
        {3.5484},
        {3.5905},
        {3.6334},
        {3.675},
        {3.718},
        {3.7601},
        {3.8026},
        {3.8452},
        {3.8881},
        {3.9309},
        {3.9737},
        {4.0163},
        {4.0533},
        {4.0565},
        {4.0568},
        {4.0593},
        {4.0614},
        {4.0634},
        {4.0665},
        {4.0639},
        {4.026},
        {3.9828},
        {3.941},
        {3.8986},
        {3.8568},
        {3.8144},
        {3.7723},
        {3.7301},
        {3.688},
        {3.6458},
        {3.6036},
        {3.5613},
        {3.5187},
        {3.4767},
        {3.434},
        {3.3919},
        {3.3491},
        {3.3065},
        {3.2642},
        {3.2209},
        {3.1788},
        {3.1357},
        {3.0926},
        {3.05},
        {3.0071},
        {2.9641},
        {2.9207},
        {2.8779},
        {2.8344},
        {2.7912},
        {2.7482},
        {2.7046},
        {2.6612},
        {2.6177},
        {2.5743},
        {2.5305},
        {2.4875},
        {2.4434},
        {2.4},
        {2.3561},
        {2.3124},
        {2.269},
        {2.225},
        {2.1813},
        {2.1378},
        {2.0935},
        {2.05},
        {2.006},
        {1.9625},
        {1.9188},
        {1.8747},
        {1.8313},
        {1.7872},
        {1.7435},
        {1.6995},
        {1.6564},
        {1.6125},
        {1.5686},
        {1.5253},
        {1.4814},
        {1.4382},
        {1.3944},
        {1.351},
        {1.3076},
        {1.2643},
        {1.221},
        {1.1777},
        {1.1342},
        {1.0914},
        {1.048},
        {1.0053},
        {0.962},
        {0.9191},
        {0.8762},
        {0.8334},
        {0.7907},
        {0.7479},
        {0.705},
        {0.6628},
        {0.6202},
        {0.5775},
        {0.5353},
        {0.4926},
        {0.4505},
        {0.4078},
        {0.3654},
        {0.3232},
        {0.281},
        {0.2391},
        {0.1963},
        {0.1547},
        {0.1118},
        {0.0692},
        {0.0235}
    }
;
std::vector<std::vector<double>> RightPaths::curveRight = {
        {0},
        {0.0335},
        {0.0813},
        {0.1369},
        {0.1928},
        {0.2487},
        {0.3046},
        {0.3605},
        {0.4164},
        {0.4724},
        {0.5293},
        {0.5847},
        {0.6405},
        {0.6963},
        {0.752},
        {0.8087},
        {0.864},
        {0.9205},
        {0.9766},
        {1.0325},
        {1.0893},
        {1.1447},
        {1.2013},
        {1.2572},
        {1.3142},
        {1.3693},
        {1.4268},
        {1.4821},
        {1.5396},
        {1.5952},
        {1.6517},
        {1.7083},
        {1.7653},
        {1.8216},
        {1.8785},
        {1.9348},
        {1.9912},
        {2.0488},
        {2.1052},
        {2.1621},
        {2.219},
        {2.2756},
        {2.3334},
        {2.3897},
        {2.4472},
        {2.504},
        {2.5617},
        {2.6189},
        {2.6758},
        {2.7333},
        {2.7911},
        {2.8481},
        {2.9056},
        {2.9632},
        {3.0209},
        {3.0789},
        {3.1358},
        {3.1935},
        {3.2521},
        {3.3091},
        {3.3671},
        {3.4257},
        {3.4825},
        {3.5412},
        {3.5988},
        {3.6568},
        {3.7149},
        {3.773},
        {3.8311},
        {3.8888},
        {3.9474},
        {4.0055},
        {4.0636},
        {4.121},
        {4.1799},
        {4.2376},
        {4.2961},
        {4.3534},
        {4.4118},
        {4.4699},
        {4.5279},
        {4.5855},
        {4.6434},
        {4.7017},
        {4.7595},
        {4.8166},
        {4.875},
        {4.9319},
        {4.9899},
        {5.0474},
        {5.1048},
        {5.1618},
        {5.2191},
        {5.2763},
        {5.3337},
        {5.3827},
        {5.3922},
        {5.3944},
        {5.3951},
        {5.3968},
        {5.399},
        {5.4007},
        {5.3973},
        {5.3507},
        {5.2938},
        {5.2356},
        {5.1781},
        {5.1198},
        {5.0623},
        {5.0044},
        {4.9465},
        {4.8887},
        {4.8309},
        {4.7731},
        {4.7153},
        {4.6579},
        {4.6},
        {4.5427},
        {4.4848},
        {4.4276},
        {4.3702},
        {4.3125},
        {4.2558},
        {4.1979},
        {4.1409},
        {4.0841},
        {4.0267},
        {3.9696},
        {3.9126},
        {3.856},
        {3.7988},
        {3.7423},
        {3.6855},
        {3.6285},
        {3.5721},
        {3.5155},
        {3.4589},
        {3.4024},
        {3.3462},
        {3.2892},
        {3.2333},
        {3.1766},
        {3.1206},
        {3.0643},
        {3.0077},
        {2.9517},
        {2.8954},
        {2.8389},
        {2.7831},
        {2.7266},
        {2.6707},
        {2.6142},
        {2.558},
        {2.502},
        {2.4455},
        {2.3895},
        {2.3331},
        {2.2772},
        {2.2203},
        {2.1642},
        {2.1081},
        {2.0514},
        {1.9952},
        {1.9385},
        {1.8822},
        {1.8256},
        {1.769},
        {1.7124},
        {1.6557},
        {1.5989},
        {1.5423},
        {1.4852},
        {1.4286},
        {1.3713},
        {1.3145},
        {1.2574},
        {1.2003},
        {1.1431},
        {1.0859},
        {1.0285},
        {0.9715},
        {0.9139},
        {0.8564},
        {0.7992},
        {0.7414},
        {0.6841},
        {0.626},
        {0.5685},
        {0.5107},
        {0.4529},
        {0.3953},
        {0.337},
        {0.2798},
        {0.2212},
        {0.1628},
        {0.1054},
        {0.0392}
    }
;

std::vector<std::vector<double>> RightPaths:: curveRLeft= {
        {0},
        {-0.0235},
        {-0.0584},
        {-0.0923},
        {-0.1253},
        {-0.1593},
        {-0.1922},
        {-0.2268},
        {-0.2611},
        {-0.2953},
        {-0.3298},
        {-0.3663},
        {-0.4008},
        {-0.4378},
        {-0.4738},
        {-0.5119},
        {-0.5495},
        {-0.5882},
        {-0.6277},
        {-0.6679},
        {-0.7086},
        {-0.7513},
        {-0.7935},
        {-0.8378},
        {-0.8823},
        {-0.9283},
        {-0.9757},
        {-1.0236},
        {-1.073},
        {-1.1233},
        {-1.1757},
        {-1.228},
        {-1.2828},
        {-1.3382},
        {-1.395},
        {-1.4532},
        {-1.5124},
        {-1.5731},
        {-1.635},
        {-1.6981},
        {-1.7623},
        {-1.8279},
        {-1.8942},
        {-1.962},
        {-2.0305},
        {-2.1003},
        {-2.1707},
        {-2.2421},
        {-2.3142},
        {-2.3872},
        {-2.4607},
        {-2.5349},
        {-2.6096},
        {-2.6847},
        {-2.7602},
        {-2.836},
        {-2.912},
        {-2.9883},
        {-3.0643},
        {-3.1408},
        {-3.2167},
        {-3.2928},
        {-3.3684},
        {-3.4439},
        {-3.519},
        {-3.5935},
        {-3.6674},
        {-3.7407},
        {-3.8135},
        {-3.8857},
        {-3.9567},
        {-4.0267},
        {-4.0965},
        {-4.1649},
        {-4.2323},
        {-4.2989},
        {-4.3641},
        {-4.4283},
        {-4.4913},
        {-4.5539},
        {-4.6144},
        {-4.6476},
        {-4.6494},
        {-4.6492},
        {-4.6477},
        {-4.6449},
        {-4.642},
        {-4.638},
        {-4.6326},
        {-4.628},
        {-4.6214},
        {-4.6158},
        {-4.6083},
        {-4.6012},
        {-4.5941},
        {-4.5861},
        {-4.5778},
        {-4.5703},
        {-4.5613},
        {-4.5533},
        {-4.5448},
        {-4.5355},
        {-4.5272},
        {-4.519},
        {-4.5097},
        {-4.5011},
        {-4.4929},
        {-4.484},
        {-4.4759},
        {-4.4669},
        {-4.459},
        {-4.4508},
        {-4.4425},
        {-4.4348},
        {-4.4267},
        {-4.419},
        {-4.4114},
        {-4.4037},
        {-4.397},
        {-4.3892},
        {-4.3824},
        {-4.3752},
        {-4.3684},
        {-4.3618},
        {-4.3553},
        {-4.3489},
        {-4.3426},
        {-4.3365},
        {-4.3303},
        {-4.3247},
        {-4.3187},
        {-4.3131},
        {-4.3076},
        {-4.3025},
        {-4.2967},
        {-4.2877},
        {-4.2399},
        {-4.1813},
        {-4.1239},
        {-4.0656},
        {-4.0081},
        {-3.951},
        {-3.8938},
        {-3.837},
        {-3.7805},
        {-3.7239},
        {-3.6677},
        {-3.6117},
        {-3.5562},
        {-3.5001},
        {-3.4449},
        {-3.3893},
        {-3.3341},
        {-3.2794},
        {-3.2243},
        {-3.1696},
        {-3.1148},
        {-3.0605},
        {-3.0062},
        {-2.9517},
        {-2.7974},
        {-1.7904},
        {-1.4942},
        {-1.4338},
        {-1.3756},
        {-1.3175},
        {-1.2612},
        {-1.2073},
        {-1.1523},
        {-1.1003},
        {-1.0485},
        {-0.9998},
        {-0.9507},
        {-0.9042},
        {-0.8572},
        {-0.8149},
        {-0.7709},
        {-0.7296},
        {-0.6913},
        {-0.6519},
        {-0.6167},
        {-0.5805},
        {-0.5494},
        {-0.5165},
        {-0.4867},
        {-0.4593},
        {-0.4337},
        {-0.4077},
        {-0.3862},
        {-0.3644},
        {-0.3458},
        {-0.3275},
        {-0.3132},
        {-0.2976},
        {-0.286},
        {-0.2761},
        {-0.2663},
        {-0.259},
        {-0.254},
        {-0.2498},
        {-0.2464},
        {-0.2466},
        {-0.2454},
        {-0.2476},
        {-0.2512},
        {-0.2538},
        {-0.2605},
        {-0.2661},
        {-0.2735},
        {-0.2817},
        {-0.2916},
        {-0.3001},
        {-0.3121},
        {-0.322},
        {-0.3352},
        {-0.3461},
        {-0.3594},
        {-0.3724},
        {-0.3849},
        {-0.3989},
        {-0.4111},
        {-0.4258},
        {-0.4385},
        {-0.4512},
        {-0.4643},
        {-0.4772},
        {-0.4895},
        {-0.4765},
        {-0.4683},
        {-0.464},
        {-0.4593},
        {-0.4549},
        {-0.4471},
        {-0.4398},
        {-0.4329},
        {-0.424},
        {-0.4133},
        {-0.4045},
        {-0.3939},
        {-0.3822},
        {-0.3713},
        {-0.36},
        {-0.3464},
        {-0.335},
        {-0.3221},
        {-0.3083},
        {-0.2955},
        {-0.2818},
        {-0.268},
        {-0.2539},
        {-0.2397},
        {-0.226},
        {-0.2108},
        {-0.1968},
        {-0.1814},
        {-0.1679},
        {-0.1517},
        {-0.1372},
        {-0.1221},
        {-0.107},
        {-0.0918},
        {-0.0771},
        {-0.0605},
        {-0.0465},
        {-0.0312},
        {-0.0142},
        {-0.0003}
    }
;
    std::vector<std::vector<double>> RightPaths:: curveRRight = {
        {0},
        {-0.034},
        {-0.0943},
        {-0.1586},
        {-0.2254},
        {-0.2915},
        {-0.3584},
        {-0.4232},
        {-0.4891},
        {-0.5552},
        {-0.6206},
        {-0.684},
        {-0.7496},
        {-0.8125},
        {-0.8765},
        {-0.9382},
        {-1.0006},
        {-1.0619},
        {-1.1225},
        {-1.1823},
        {-1.2415},
        {-1.2988},
        {-1.3566},
        {-1.4124},
        {-1.4678},
        {-1.5218},
        {-1.5744},
        {-1.6265},
        {-1.6771},
        {-1.7268},
        {-1.7744},
        {-1.8221},
        {-1.8672},
        {-1.9119},
        {-1.955},
        {-1.9968},
        {-2.0376},
        {-2.0769},
        {-2.115},
        {-2.1519},
        {-2.1877},
        {-2.2221},
        {-2.2558},
        {-2.2881},
        {-2.3195},
        {-2.3498},
        {-2.3794},
        {-2.408},
        {-2.4358},
        {-2.4629},
        {-2.4893},
        {-2.5152},
        {-2.5405},
        {-2.5653},
        {-2.5898},
        {-2.614},
        {-2.6381},
        {-2.6617},
        {-2.6857},
        {-2.7092},
        {-2.7334},
        {-2.7572},
        {-2.7817},
        {-2.8062},
        {-2.8311},
        {-2.8566},
        {-2.8827},
        {-2.9094},
        {-2.9365},
        {-2.9644},
        {-2.9933},
        {-3.0233},
        {-3.0535},
        {-3.0851},
        {-3.1178},
        {-3.1511},
        {-3.1859},
        {-3.2217},
        {-3.2587},
        {-3.2961},
        {-3.3357},
        {-3.3524},
        {-3.3506},
        {-3.3508},
        {-3.3523},
        {-3.3551},
        {-3.358},
        {-3.362},
        {-3.3674},
        {-3.372},
        {-3.3785},
        {-3.3842},
        {-3.3916},
        {-3.3988},
        {-3.4058},
        {-3.4139},
        {-3.4222},
        {-3.4297},
        {-3.4386},
        {-3.4467},
        {-3.4552},
        {-3.4645},
        {-3.4727},
        {-3.481},
        {-3.4903},
        {-3.4989},
        {-3.5071},
        {-3.516},
        {-3.524},
        {-3.5331},
        {-3.541},
        {-3.5491},
        {-3.5575},
        {-3.5651},
        {-3.5733},
        {-3.581},
        {-3.5886},
        {-3.5963},
        {-3.603},
        {-3.6108},
        {-3.6176},
        {-3.6248},
        {-3.6316},
        {-3.6382},
        {-3.6447},
        {-3.6511},
        {-3.6573},
        {-3.6635},
        {-3.6697},
        {-3.6753},
        {-3.6813},
        {-3.6869},
        {-3.6924},
        {-3.6975},
        {-3.7033},
        {-3.704},
        {-3.6694},
        {-3.6279},
        {-3.5854},
        {-3.5437},
        {-3.5012},
        {-3.4581},
        {-3.4154},
        {-3.3722},
        {-3.3288},
        {-3.2854},
        {-3.2416},
        {-3.1975},
        {-3.153},
        {-3.1092},
        {-3.0644},
        {-3.0199},
        {-2.975},
        {-2.9297},
        {-2.8849},
        {-2.8396},
        {-2.7944},
        {-2.7486},
        {-2.703},
        {-2.6574},
        {-2.7128},
        {-3.6306},
        {-3.8419},
        {-3.8198},
        {-3.7978},
        {-3.7781},
        {-3.7592},
        {-3.7401},
        {-3.7246},
        {-3.7084},
        {-3.6945},
        {-3.6797},
        {-3.6678},
        {-3.6556},
        {-3.6463},
        {-3.6346},
        {-3.627},
        {-3.6189},
        {-3.6102},
        {-3.6049},
        {-3.5976},
        {-3.5937},
        {-3.5869},
        {-3.5841},
        {-3.5805},
        {-3.5766},
        {-3.5731},
        {-3.5722},
        {-3.5688},
        {-3.5678},
        {-3.5657},
        {-3.5653},
        {-3.563},
        {-3.5638},
        {-3.5626},
        {-3.5615},
        {-3.5621},
        {-3.562},
        {-3.5613},
        {-3.5615},
        {-3.5625},
        {-3.5614},
        {-3.5632},
        {-3.563},
        {-3.5628},
        {-3.5649},
        {-3.5642},
        {-3.5656},
        {-3.5664},
        {-3.5673},
        {-3.5675},
        {-3.5699},
        {-3.5695},
        {-3.572},
        {-3.5718},
        {-3.5743},
        {-3.5749},
        {-3.5762},
        {-3.5782},
        {-3.5789},
        {-3.5816},
        {-3.5818},
        {-3.5839},
        {-3.586},
        {-3.5875},
        {-3.5889},
        {-3.5879},
        {-3.5354},
        {-3.4435},
        {-3.3477},
        {-3.2524},
        {-3.1567},
        {-3.0645},
        {-2.9719},
        {-2.8788},
        {-2.7875},
        {-2.6982},
        {-2.6071},
        {-2.5176},
        {-2.4293},
        {-2.3403},
        {-2.2516},
        {-2.1651},
        {-2.0765},
        {-1.9894},
        {-1.9032},
        {-1.816},
        {-1.7296},
        {-1.6435},
        {-1.5575},
        {-1.4718},
        {-1.3855},
        {-1.3006},
        {-1.2146},
        {-1.13},
        {-1.0435},
        {-0.9596},
        {-0.874},
        {-0.7891},
        {-0.7042},
        {-0.6195},
        {-0.534},
        {-0.4507},
        {-0.3648},
        {-0.2796},
        {-0.1962},
        {-0.1096}
    }
;

std::vector<std::vector<double>> RightPaths::fwdLeft = {
        {0},
        {0.0284},
        {0.0762},
        {0.1256},
        {0.1755},
        {0.2255},
        {0.2754},
        {0.3252},
        {0.3752},
        {0.4252},
        {0.4752},
        {0.5252},
        {0.5751},
        {0.6251},
        {0.675},
        {0.7251},
        {0.7751},
        {0.8251},
        {0.8751},
        {0.9251},
        {0.9751},
        {1.0251},
        {1.0751},
        {1.1251},
        {1.175},
        {1.225},
        {1.275},
        {1.325},
        {1.375},
        {1.425},
        {1.475},
        {1.525},
        {1.575},
        {1.625},
        {1.675},
        {1.725},
        {1.775},
        {1.825},
        {1.875},
        {1.925},
        {1.975},
        {2.025},
        {2.075},
        {2.125},
        {2.175},
        {2.2211},
        {2.197},
        {2.147},
        {2.097},
        {2.047},
        {1.997},
        {1.947},
        {1.897},
        {1.847},
        {1.797},
        {1.747},
        {1.697},
        {1.647},
        {1.597},
        {1.547},
        {1.4969},
        {1.4469},
        {1.3969},
        {1.3469},
        {1.2969},
        {1.2469},
        {1.1969},
        {1.1469},
        {1.0969},
        {1.0469},
        {0.9969},
        {0.9469},
        {0.8969},
        {0.8469},
        {0.7969},
        {0.7468},
        {0.6968},
        {0.6469},
        {0.5969},
        {0.5469},
        {0.4968},
        {0.4467},
        {0.3967},
        {0.3467},
        {0.2966},
        {0.2465},
        {0.1966},
        {0.1466},
        {0.0964},
        {0.0437}
    }
;
std::vector<std::vector<double>> RightPaths::fwdRight = {
        {0},
        {0.0284},
        {0.0762},
        {0.1256},
        {0.1755},
        {0.2255},
        {0.2754},
        {0.3252},
        {0.3752},
        {0.4252},
        {0.4752},
        {0.5252},
        {0.5751},
        {0.6251},
        {0.675},
        {0.7251},
        {0.7751},
        {0.8251},
        {0.8751},
        {0.9251},
        {0.9751},
        {1.0251},
        {1.0751},
        {1.1251},
        {1.175},
        {1.225},
        {1.275},
        {1.325},
        {1.375},
        {1.425},
        {1.475},
        {1.525},
        {1.575},
        {1.625},
        {1.675},
        {1.725},
        {1.775},
        {1.825},
        {1.875},
        {1.925},
        {1.975},
        {2.025},
        {2.075},
        {2.125},
        {2.175},
        {2.2211},
        {2.197},
        {2.147},
        {2.097},
        {2.047},
        {1.997},
        {1.947},
        {1.897},
        {1.847},
        {1.797},
        {1.747},
        {1.697},
        {1.647},
        {1.597},
        {1.547},
        {1.4969},
        {1.4469},
        {1.3969},
        {1.3469},
        {1.2969},
        {1.2469},
        {1.1969},
        {1.1469},
        {1.0969},
        {1.0469},
        {0.9969},
        {0.9469},
        {0.8969},
        {0.8469},
        {0.7969},
        {0.7468},
        {0.6968},
        {0.6469},
        {0.5969},
        {0.5469},
        {0.4968},
        {0.4467},
        {0.3967},
        {0.3467},
        {0.2966},
        {0.2465},
        {0.1966},
        {0.1466},
        {0.0964},
        {0.0437}
    }
;