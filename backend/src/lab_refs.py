""" lab_refs.py
Collection of reference lab values

Authors:
    Brendan Grau <https://github.com/Victoriam7>

License:
    © 2022 BeyondRGB
    This code is licensed under the MIT license (see LICENSE.txt for details)
"""
import numpy as np

LAB_REF = np.array(
          [[94.33448348, 20.35894153, 78.50353911, 79.78204965, 94.39928291,
            52.61788438, 49.93427259, 39.43549152, 70.95513244, 94.35470480,
            22.82073003, 40.19219875, 60.63328343, 68.57095285, 36.43050292,
            21.97584071, 24.35534235, 27.61794809, 62.87281971, 51.10395416,
            29.48025203, 39.22291164, 60.51127124, 77.38425061, 22.95659409,
            59.25743087, 39.68087128, 89.43611172, 80.80612282, 87.06716127,
            28.09846411, 51.42071336, 17.41136928, 29.31211778, 55.66699154,
            22.36649520, 94.34411610, 75.93317890, 52.30446986, 22.59601095,
            49.96223519, 48.93916401, 30.31362647, 78.49023475, 37.29750193,
            61.03344390, 75.87944794, 58.70318498, 60.31082436, 80.40179806,
            59.45039197, 68.88622188, 41.55768956, 40.68274093, 62.48871268,
            35.15938538, 65.26658605, 24.86730837, 35.66433585, 52.88794718,
            94.36351028, 79.43316724, 61.31050541, 45.99811532, 28.08564665,
            78.92325418, 52.52699222, 21.66775113, 47.53007435, 94.27865108,
            52.81140501, 54.25427511, 65.28544766, 50.61134425, 69.83745818,
            47.18145194, 34.96756090, 60.46925113, 33.16695676, 59.44465166,
            68.37453813, 59.25277585, 68.69922422, 73.08325352, 69.61860881,
            47.35128816, 9.341489977, 89.04100395, 59.22898816, 59.69276353,
            58.41284348, 41.41801122, 79.77888984, 22.43887950, 51.33308343,
            80.22039878, 41.70621053, 70.50844820, 40.59473549, 47.82814103,
            35.78440098, 22.99243931, 86.58886462, 61.84874031, 79.38926505,
            50.21194515, 69.77565558, 28.29652163, 79.71587019, 23.04520126,
            29.55488460, 43.55320519, 49.54414857, 81.01839049, 49.29418818,
            89.68305280, 42.57227218, 32.50982611, 65.85173650, 8.007262590,
            94.32211455, 32.12528521, 69.73732299, 60.67658787, 52.56707666,
            94.3604513, 90.14104866, 60.81551357, 40.73249021, 94.34029536],

           [-0.8295287716, -7.6494634310, -29.936600010, -19.213514230,
            -0.8352536120, -1.2164675890, 43.1272566700, -36.193716570,
            -24.109925210, -0.8369240705, -24.356354730, -20.550359560,
            -38.285407620, -11.689742410, 50.5296577300, 7.14776444800,
            4.65469590900, -27.800459130, -32.670843440, -22.874000390,
            -12.865216180, -31.138952470, -21.858321380, -23.589238540,
            24.0470857100, 41.1857531300, 44.5383073600, -0.6176483839,
            2.34108983900, -6.6309883590, -23.111259150, -43.074960060,
            -0.6990237041, 22.0422589200, 41.2393860000, -6.2225562480,
            -0.8204357770, -0.2742299159, -0.3943203525, -6.2476581850,
            -11.410803550, -20.045259410, -0.3392815309, 20.1953544400,
            -13.512962630, -41.692044280, -1.0284644450, -3.3177004240,
            -10.850024950, -1.6188576140, -15.151355210, -11.777081180,
            -0.3537379718, -7.8259523940, 39.0381060400, 57.5518243300,
            -0.9228170378, 6.65253212700, 8.69388343000, -1.2319201410,
            -0.8190935566, 4.33466328600, -0.2817173477, -18.872551690,
            22.9435798500, 8.07963020700, -1.2028349790, -0.4189031617,
            -14.879325810, -0.8230124065, -1.2310107840, 3.29895892600,
            -0.9293274875, 11.0520435700, -22.674185370, 52.7413358300,
            -0.7746311923, 3.56117464200, -1.0199188330, -9.6333523610,
            5.05540183100, 9.14017638800, -0.8322727467, -36.311880680,
            31.7618585200, -38.050388430, -0.1238524162, -0.8339448178,
            7.28149608500, -5.0959421580, 1.39320915300, 2.90906356500,
            -0.8186219201, 7.16599111800, 13.9670529400, 9.95124321200,
            24.2348605300, 2.98695536100, 14.9750678200, -15.756018820,
            0.68123971050, 0.28550230230, -1.7444844940, 25.8707515200,
            4.51752918600, 3.90594665000, 13.7445902100, 16.6566465600,
            6.87406331100, -20.207062040, 10.6543278700, 24.9765054100,
            54.5537178400, 19.2241614300, 34.2599638600, 6.48964496600,
            20.2261041000, 8.88710591500, 13.2637553200, 2.68157755100,
            -0.8208181495, 8.98733621500, 30.6378201300, 25.9935409200,
            -1.2032292180, -0.8236262020, 3.97041875400, 15.3879236900,
            23.2075391100, -0.8244831597],

           [2.64507087100, -1.1910972820, 1.80369813200, 43.8156834900,
            2.69217017200, 1.77491385200, 44.3032039000, -25.313636940,
            -16.813023230, 2.58557873100, 5.63514507500, -0.2227805219,
            0.55720148100, -28.155286420, 2.50330656000, -0.5510216160,
            8.54084988800, -22.553997250, -21.909267000, -18.082848900,
            11.3315305000, -0.7519362044, 0.79853949840, 1.92788597400,
            6.32182282600, 41.3493741300, 48.3616609400, 1.38540233800,
            14.8327641000, -3.5724193770, 22.4034914000, 0.25225393670,
            -0.5383055084, 21.5408627300, 65.6440877200, -24.290851890,
            2.70455743200, 0.40415250710, -0.5874232086, -7.0646990570,
            19.2729102200, 45.3847824300, -0.5341049348, 29.0916543200,
            -43.623280620, 42.7932200300, 1.18853899700, -43.099163590,
            -40.165796460, -10.908244840, 31.5541476400, 20.8413455500,
            0.39231193000, -23.866576560, 4.38058916500, 43.3072080200,
            1.82991010600, -57.404855160, -59.831734780, 1.73498207500,
            2.77877618800, 42.0283925200, 1.93466474800, 24.1742054100,
            -23.235471710, 79.5235406100, 1.81293832000, -1.0664300990,
            15.9643712900, 2.66382358500, 1.79653455500, 66.4879947300,
            1.81207084000, -16.676713250, 55.7329372100, 5.66807807800,
            1.31167648000, 15.1755310700, 9.96946377800, -30.406790620,
            43.6179203600, 59.7402001600, 0.89746490740, 0.53959587820,
            55.0629527900, -26.873298480, -0.2444981856, -2.1299830720,
            27.6138052800, -14.323561100, 15.2973006600, 15.3086870700,
            1.82422713300, 3.00134068400, 37.5879509200, 27.5863867300,
            4.07411648100, 15.6486629700, 21.0723618900, -41.731050090,
            43.6820849500, 7.74621503600, 0.26717169300, 21.0122537300,
            14.0008250000, 13.6467370400, 24.9205056200, 17.2043026500,
            53.8412207700, -19.557967540, 9.41254154900, 16.1678039900,
            32.5300671000, 1.12012018400, 4.06798255100, 5.08622327900,
            -18.621545850, -13.049845060, -18.454840570, -11.363471500,
            2.76948932500, 6.09708637300, 0.29801429240, 3.78146591900,
            1.82185441300, 2.70283173500, 2.44509408700, -20.201188510,
            -25.139258790, 2.65620487400]])
