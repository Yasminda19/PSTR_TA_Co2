[{"id":"d6230d5f.c05e","type":"serial in","z":"b9075383.db257","name":"","serial":"1b8769a6.621dc6","x":91,"y":135,"wires":[["ea730c90.ebc4b","84c15113.4ecec","e146cbcf.251818"]]},{"id":"ea730c90.ebc4b","type":"debug","z":"b9075383.db257","name":"","active":true,"console":"false","complete":"false","x":501,"y":274,"wires":[]},{"id":"e146cbcf.251818","type":"twitter out","z":"b9075383.db257","twitter":"","name":"Tweet","x":689,"y":144,"wires":[]},{"id":"84c15113.4ecec","type":"ui_text","z":"b9075383.db257","group":"90f1c978.bba628","order":0,"width":0,"height":0,"name":"CO in PPM","label":"Arduino Reading","format":"{{msg.payload}}","layout":"col-center","x":467,"y":41,"wires":[]},{"id":"1b8769a6.621dc6","type":"serial-port","z":"b9075383.db257","serialport":"COM7","serialbaud":"57600","databits":"8","parity":"none","stopbits":"1","newline":"\\n","bin":"false","out":"char","addchar":false},{"id":"90f1c978.bba628","type":"ui_group","z":"b9075383.db257","name":"CarbonMonoxide in Atmosphere","tab":"93b83a33.771108","disp":true,"width":"9"},{"id":"93b83a33.771108","type":"ui_tab","z":"b9075383.db257","name":"Home","icon":"dashboard"}]  