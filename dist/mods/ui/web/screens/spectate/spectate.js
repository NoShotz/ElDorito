var cardOpacity = 0.6;

var teamArray = [
    {name: 'Red', color: '#9A3636'},
    {name: 'Blue', color: '#305694'},
    {name: 'Green', color: '#526A08'},
    {name: 'Orange', color: '#F08A0C'},
    {name: 'Purple', color: '#1D1052'},
    {name: 'Gold', color: '#D5A831'},   
    {name: 'Brown', color: '#4E331B'}, 
    {name: 'Pink', color: '#FC9AC1'}, 
    {name: 'White', color: '#D8D8D8'}, 
    {name: 'Black', color: '#0B0B0B'}           
];

var ffaArray = {
    '#282828': '#4A484B',
    '#7C7C7C': '#AAA8AC',
    '#C3C3C3': '#E9E6E5',
    '#620B0B': '#9B2D2C',
    '#BD2B2B': '#EE6255',
    '#E24444': '#FF8071',   
    '#BC4D00': '#EC8B00', 
    '#F4791F': '#FF9F38', 
    '#FFA362': '#FFC18B', 
	'#A77708': '#D5A514', 
    '#DD9A08': '#FEB612',
	'#FFBC3B': '#FED363', 
	'#1F3602': '#385B19', 
    '#546E26': '#8C984E',
	'#B3E164': '#DCFB93', 
	'#0A3B3F': '#176370', 
    '#178C95': '#34ACBA',
	'#54DDDB': '#82F3FE', 
	'#0B2156': '#2B488C', 
    '#1D4BBC': '#3580E6',
	'#5D85EB': '#8BA9FF', 
	'#1D1052': '#3D378F', 
    '#5438CF': '#3580E6',
	'#A18CFF': '#BDAAFF', 
	'#460014': '#7F0C31', 
    '#AF0E46': '#E4427B',
	'#FF4D8A': '#FF8CA9', 
	'#1C0D02': '#3A2719', 
    '#774D31': '#A78665',
	'#C69069': '#EFB89A'
};

dew.on("spectate_change", function(e){
    dew.show();
    dew.getScoreboard().then(function (x){ 
        var playerIndex = x.players.findIndex(i => i.name == e.data.displayName);
        showSpectateOverlay(playerIndex, x.players, x.hasTeams, JSON.parse(x.playersInfo));
    });
});

dew.on("spectate_end", function(e){
    dew.hide();
});

function showSpectateOverlay(i, lobby, teamGame, playersInfo){
    var emblemPath;
	var hostPath = 'dew://assets/emblems/crown.png';
    if(lobby.length > 0){
        $('#spectatingOverlay').empty();
        var bgColor = lobby[i].color;
		if(bgColor in ffaArray){
				bgColor = ffaArray[bgColor];
			}
        if(teamGame){
            bgColor = teamArray[lobby[i].team].color;
        }
        $('#spectatingOverlay').append(
            $('<tr>', {
                css: {
                    background: "-webkit-linear-gradient(left, " + hexToRgb(bgColor,1) + " 11.25%,rgba(0,0,0,0.5) 11.25%)"
                },
                id: lobby[i].name,
                class: 'player clickable',
                'data-uid': lobby[i].UID,
                'data-color': bgColor,
                'data-score':lobby[i].score,
                'data-playerIndex':lobby[i].playerIndex,
            })
            .append($('<td class="name">').text(lobby[i].name)) //name
        );   
		if(playersInfo[lobby[i].playerIndex]){
			emblemPath = playersInfo[lobby[i].playerIndex].e;
		}else{
			emblemPath = 'dew://assets/emblems/generic.png'; 
		}                
        $("[data-playerIndex='" + lobby[i].playerIndex + "'] .name").prepend('<img class="emblem" src="'+emblemPath+'">');
        $("[data-playerIndex='" + lobby[i].playerIndex + "'] .name").append('<img class="arrows" src="sort_both.png">');
		if(lobby[i].isHost)
		$("[data-playerIndex='" + lobby[i].playerIndex + "'] .name").append('<img class="emblem" src="'+hostPath+'" style="float: right;">');
    }  
}

function hexToRgb(hex, opacity){
    var result = /^#?([a-f\d]{2})([a-f\d]{2})([a-f\d]{2})$/i.exec(hex);
    return "rgba(" + parseInt(result[1], 16) + "," + parseInt(result[2], 16) + "," + parseInt(result[3], 16) + "," + opacity + ")";
}