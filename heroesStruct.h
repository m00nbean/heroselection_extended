#pragma once
#ifndef string
#include<string>
#endif // !string
const short MELEE = 0;
const short RANGE = 1;
const short poolSize = 121;

struct hero 
{
	bool inbot = false;
	char name[20] = {};
	unsigned hero_id = 999;
	char command[50] = {};
	short range = MELEE;
	int carry = 0;
	int support = 0;
	int nuker = 0;
	int control = 0;
	int durabil = 0;
	int init = 0;
	enum class talent_id {e_carry,e_support,e_nuker,e_control,e_durabil,e_init};
	

};

enum class stage{first=1,second,third,forth,fifth};

hero temp = { };

	hero abaddon =	{ true,"Abaddon",0,"npc_dota_hero_abaddon",MELEE,1,2,0,0,2,0};

	hero alchemist = { false,"Alchemist",1,"npc_dota_hero_alchemist",MELEE,
					2,1,1,1,2,1 };
	hero ancient_app = { true,"Ancient Apparition",2,"npc_dota_hero_ancient_apparition",
					RANGE,0,2,1,1 };
	hero antimage = { false,"Anti-Mage",3,"npc_dota_hero_antimage",MELEE,
					3,0,0,0 };
	hero arc = { false,"Arc Warden",4,"npc_dota_hero_arc_warden",RANGE,
					2, 0,1};
	hero axe = { true,"Axe",5,"npc_dota_hero_axe",MELEE,
					1,0,0,2,3,3 };
	hero bane = { true,"Bane",6,"npc_dota_hero_bane",RANGE,
					0,2,1,3,1 };
	hero batrider = { true,"Batrider",7,"npc_dota_hero_batrider",RANGE,
					0,0,0,2,0,3 };
	hero beastmaster = { false,"Beastmaster",8,"npc_dota_hero_beastmaster",MELEE,
					0,0,1,2,2,2 };
	hero bloodseeker = { true,"Bloodseeker",9,"npc_dota_hero_bloodseeker",MELEE,
						1,0,1,1,0,1 };
	hero bountyhunter = { false,"Bounty Hunter",10,"npc_dota_hero_bounty_hunter",MELEE,
						0,0,1, };
	hero brewmaster = { false,"Brewmaster",11,"npc_dota_hero_brewmaster", MELEE,
						1,0,1,2,2,3 };
	hero bristeback = { true,"Bristleback",12,"npc_dota_hero_bristleback",MELEE,
						2,0,1,0,3,1 };
	hero broodmother = { false,"Broodmother",13,"npc_dota_hero_broodmother",MELEE,
						1,0,1,0,0 };
	hero centaur = { true,"Centaur Warrunner",14,"npc_dota_hero_centaur",MELEE,
						0,0,1,1,3,3 };
	hero chaos = { true,"Chaos Knight",15,"npc_dota_hero_chaos_knight",MELEE,
						3,0,0,2,2,1 };
	hero chen = { false,"Chen",16,"npc_dota_hero_chen",RANGE,
						0,2, };
	hero clinkz = { true,"Clinkz",17,"npc_dota_hero_clinkz",RANGE,
						2 };
	hero clockwerk = { false,"Clockwerk",18,"npc_dota_hero_rattletrap",MELEE,
						0,0,1,2,1,3 };
	hero maiden = { true,"Crystal Maiden",19,"npc_dota_hero_crystal_maiden",RANGE,
						0,3,2,2 };
	hero darkseer = { false,"Dark Seer",20,"npc_dota_hero_dark_seer",MELEE,
						0,0,0,1,0,1 };
	hero willow = { true,"Dark Willow",21,"npc_dota_hero_dark_willow",RANGE,
						0,2,2,1, };
	hero dawnbreaker = { false,"Dawnbreaker",22,"npc_dota_hero_dawnbreaker",MELEE,
						1,0,0,0,2 };
	hero dazzle = { true,"Dazzle",23,"npc_dota_hero_dazzle",RANGE,
						0,3,1,1 };
	hero death_prophet = { true,"Death Prophet",24,"npc_dota_hero_death_prophet",RANGE,
						1,0,1,1 };
	hero disruptor = { true,"Disruptor",25,"npc_dota_hero_disruptor",RANGE,
						0,2,1,2,0,1 };
	hero doom = { true,"Doom",26,"npc_dota_hero_doom",MELEE,
						1,0,1,2,2,2 };
	hero dragon = { true,"Dragon Knight",27,"npc_dota_hero_dragon_knight",MELEE,
						2,0,1,2,2,1 };
	hero drow = { true,"Drow Ranger", 28,"npc_dota_hero_drow_ranger",RANGE,
						2,0,0,1 };
	hero earth_spirit = { true,"Earth Spirit",29,"npc_dota_hero_earth_spirit",MELEE,
						0,0,2,1,1,1 };
	hero earthshaker = { true,"Earthshaker",30,"npc_dota_hero_earthshaker",MELEE,
						0,1,1,2,0,3 };
	hero elder = { false,"Elder Titan",31,"npc_dota_hero_elder_titan",MELEE,
						0,0,1,1,1,2 };
	hero ember = { false,"Ember Spirit",32,"npc_dota_hero_ember_spirit",MELEE,
						2,0,1,1,0,1 };
	hero enchantress = { true,"Enchantress",33,"npc_dota_hero_enchantress",RANGE,
						0,2,0,1,1 };
	hero enigma = { false,"Enigma",34,"npc_dota_hero_enigma",RANGE,
						0,0,0,2,0,2 };
	hero face_void = { false,"Faceless Void",35,"npc_dota_hero_faceless_void",MELEE,
						2,0,0,2,1,3 };
	hero grimsptoke = { true,"Grimstroke",36,"npc_dota_hero_grimstroke",RANGE,
						0,2,2,2 };
	hero gyrocopter = { true,"Gyrocopter",37,"npc_dota_hero_gyrocopter",RANGE,
						3,0,1,1, };
	hero hoodwink = { false,"Hoodwink",38,"npc_dota_hero_hoodwink",RANGE,
						0,2,2,1 };
	hero huskar = { true,"Huskar",39,"npc_dota_hero_huskar",RANGE,
						2,0,0,0,2,1 };
	hero invoker = { false,"Invoker",40,"npc_dota_hero_invoker",RANGE,
						1,0,3,2 };
	hero io = { false,"Io",41,"npc_dota_hero_wisp",RANGE,
						0,3,1 };
	hero jakiro = { true,"Jakiro",42,"npc_dota_hero_jakiro",RANGE,
						0,1,2,1 };
	hero juggernaut = { true,"Jugernaut",43,"npc_dota_hero_juggernaut",MELEE,
						2,0,1 };
	hero kotl = { false,"Keeper of the Light",44,"npc_dota_hero_keeper_of_the_light",RANGE,
						0,3,2,1 };
	hero kunkka = { true,"Kunkka",45,"npc_dota_hero_kunkka",MELEE,
						2,1,1,2,1,2 };
	hero legion = { false,"Legion Commander",46,"npc_dota_hero_legion_commander",MELEE,
						1,0,1,2,1,1 };
	hero leshrac = { true,"Leshrac",47,"npc_dota_hero_leshrac",RANGE,
						1,1,3,1 };
	hero lich = { true,"Lich",48,"npc_dota_hero_lich",RANGE,
						0,3,2 };
	hero lifestealer = { false,"Lifestealer",49,"npc_dota_hero_life_stealer",MELEE,
						2,0,0,1,2 };
	hero lina = { true,"Lina",50,"npc_dota_hero_lina",RANGE,
						1,1,3,1 };
	hero lion = { true,"Lion",51,"npc_dota_hero_lion",RANGE,
						0,2,3,3,0,2 };
	hero lone_druid = { false,"Lone Druid",52,"npc_dota_hero_lone_druid",RANGE,
						2,0,0,0,1 };
	hero luna = { true,"Luna",53,"npc_dota_hero_luna",RANGE,
						2,0,2 };
	hero lycan = { true,"Lycan",54,"npc_dota_hero_lycan",MELEE,
						2,0,0,0,1 };
	hero magnus = { true,"Magnus",55,"npc_dota_hero_magnataur",MELEE,
						0,0,1,2,0,3 };
	hero mars = { true,"Mars",56,"npc_dota_hero_mars",MELEE,
						1,0,0,2,3,2 };
	hero medusa = { false,"Medusa",57,"npc_dota_hero_medusa",RANGE,
						3,0,0,1,1 };
	hero meepo = { false,"Meepo",58,"npc_dota_hero_meepo",MELEE,
						2,0,2,1,0,1 };
	hero mirana = { true,"Mirana",59,"npc_dota_hero_mirana",RANGE,
						1,1,1,1 };
	hero monkey = { false,"Monkey King",60,"npc_dota_hero_monkey_king",MELEE,
						2,0,0,1,0,1 };
	hero morphling = { false,"Morphling",61,"npc_dota_hero_morphling",RANGE,
						3,0,1,1,2 };
	hero naga = { false,"Naga Siren",62,"npc_dota_hero_naga_siren",MELEE,
						3,1,0,2,0,1 };
	hero nature_prophet = { false,"Nature's Prophet",63,"npc_dota_hero_furion",RANGE,
						1,0,1, };
	hero necrophos = { true,"Necrophos",64,"npc_dota_hero_necrolyte",RANGE,
						1,0,2,1,1 };
	hero stalker = { false,"Night Stalker",65,"npc_dota_hero_night_stalker",MELEE,
						1,0,1,2,2,2 };
	hero nyx = { true,"Nyx Assasin",66,"npc_dota_hero_nyx_assassin",MELEE,
						0,0,2,2,0,2 };
	hero ogre = { true,"Ogre Magi",67,"npc_dota_hero_ogre_magi",MELEE,
						0,2,2,2,1,1 };
	hero omniknight = { true,"Omniknight",68,"npc_dota_hero_omniknight",MELEE,
						0,2,1,0,1 };
	hero oracle = { true,"Oracle",69,"npc_dota_hero_oracle",RANGE,
						0,3,3,2 };
	hero obsidian = { false,"Outworld Destroyer",70,"npc_dota_hero_obsidian_destroyer",RANGE,
						2,0,2,1 };
	hero pangolier = { true,"Pangolier",71,"npc_dota_hero_pangolier",MELEE,
						2,0,2,1,1,2 };
	hero phantom_assasin = { true,"Phantom Assasin",72,"npc_dota_hero_phantom_assassin",MELEE,
						3 };
	hero phantom_lancer={false,"Phantom Lanser",73,"npc_dota_hero_phantom_lancer",MELEE,
						2,0,1 }; 
	hero phoenix = { true,"Phoenix",74,"npc_dota_hero_phoenix",RANGE,
						0,2,3,1,0,2};
	hero puck = { false,"Puck",75,"npc_dota_hero_puck",RANGE,
						0,0,2,3,0,3 };
	hero pudge = { true,"Pudge",76,"npc_dota_hero_pudge",MELEE,
						0,0,1,2,2,2 };
	hero pugna = { false,"Pugna",77,"npc_dota_hero_pugna",RANGE,
						0,0,2 };
	hero qop = { false,"Queen of Pain",78,"npc_dota_hero_queenofpain",RANGE,
						1,0,3 };
	hero razor = { true,"Razor",79,"npc_dota_hero_razor",RANGE,
						2,0,1,0,2 };
	hero riki = { false,"Riki",80,"npc_dota_hero_riki",MELEE,
						2,0,0,1 };
	hero rubick = { false,"Rubick",81,"npc_dota_hero_rubick",RANGE,
						0,2,1,1 };
	hero sand_king = { true,"Sand King",82,"npc_dota_hero_sand_king",MELEE,
						0,1,2,2,0,3 };
	hero shadow_demon = { true,"Shadow Demon",83,"npc_dota_hero_shadow_demon",RANGE,
						0,2,1,2,0,1 };
	hero shadow_fiend = { true,"Shadow Fiend",84,"npc_dota_hero_nevermore",RANGE,
						2,0,3 };
	hero shadow_shaman = { true,"Shadow Shaman",85,"npc_dota_hero_shadow_shaman",RANGE,
						0,2,2,3,0,1 };
	hero silenser = { false,"Silenser",86,"npc_dota_hero_silencer",RANGE,
						1,1,1,2,0,1 };
	hero skywrath = { true,"Skywrath Mage",87,"npc_dota_hero_skywrath_mage",RANGE,
						0,2,3,1 };
	hero slardar = { true,"Slardar",88,"npc_dota_hero_slardar",MELEE,
						2,0,0,1,2,2 };
	hero slark = { false,"Slark",89,"npc_dota_hero_slark",MELEE,
						2,0,1,1 };
	hero snapfire = { true,"Snapfire",90,"npc_dota_hero_snapfire",RANGE,
						0,1,3,1 };
	hero sniper = { true,"Sniper",91,"npc_dota_hero_sniper",RANGE,
						3,0,1 };
	hero spectre = { false,"Spectre",92,"npc_dota_hero_spectre",MELEE,
						3,0,0,0,1 };
	hero spirit_breaker = { false,"Spirit Breaker",93,"npc_dota_hero_spirit_breaker",MELEE,
						1,0,0,2,2,2 };
	hero storm = { false,"Storm Spirit",94,"npc_dota_hero_storm_spirit",RANGE,
						2,0,2,1,0,1 };
	hero sven = { true,"Sven",95,"npc_dota_hero_sven",MELEE,
						2,0,1,2,2,2 };
	hero techies = { false,"Techies",96,"npc_dota_hero_techies",RANGE,
						0,0,3,1 };
	hero templar = { false,"Templar Assasin",97,"npc_dota_hero_templar_assassin",RANGE,
						2 };
	hero terrorblade = { false,"Terrorblade",98,"npc_dota_hero_terrorblade",MELEE,
						3,0,1 };
	hero tidehunter = { true,"Tidehunter",99,"npc_dota_hero_tidehunter",MELEE,
						1,0,1,2,2,3 };
	hero timbersaw = { false,"Timbersaw",100,"npc_dota_hero_shredder",MELEE,
						0,0,3,0,2 };
	hero tinker = { false,"Tinker",101,"npc_dota_hero_tinker",RANGE,
						1,0,3 };
	hero tiny = { true,"Tiny",102,"npc_dota_hero_tiny",MELEE,
						3,0,2,1,1,2 };
	hero treant = { true,"Treant Protector",103,"npc_dota_hero_treant",MELEE,
						0,3,0,1,1,2 };
	hero troll = { true,"Troll Warlord",104,"npc_dota_hero_troll_warlord",MELEE,
						3,0,0,1,1 };
	hero tusk = { true,"Tusk",105,"npc_dota_hero_tusk",MELEE,
						0,0,1,2,0,2 };
	hero underlord = { true,"Underlord",106,"npc_dota_hero_abyssal_underlord",MELEE,
						1,1,1,1,1 };
	hero undying = { true,"Undying",107,"npc_dota_hero_undying",MELEE,
						0,2,1,1,2 };
	hero ursa = { true,"Ursa",108,"npc_dota_hero_ursa",MELEE,
						2,0,0,1,1 };
	hero vengeful = { true,"Vengeful Spirit",109,"npc_dota_hero_vengefulspirit",RANGE,
						0,3,1,2,0,2 };
	hero venomancer = { true,"Venomancer",110,"npc_dota_hero_venomancer",RANGE,
						0,2,1,1,0,1 };
	hero viper = { true,"Viper",111,"npc_dota_hero_viper",RANGE,
						1,0,0,1,2,1 };
	hero visage = { true,"Visage",112,"npc_dota_hero_visage",RANGE,
						0,1,2,1,1 };
	hero void_spirit = { false,"Void Spirit",113,"npc_dota_hero_void_spirit",MELEE,
						2,0,2,1 };
	hero warlock = { true,"Warlock",114,"npc_dota_hero_warlock",RANGE,
						0,1,0,1,0,2 };
	hero weaver = { false,"Weaver",115,"npc_dota_hero_weaver",RANGE,
						2 };
	hero windranger = { true,"Windranger",116,"npc_dota_hero_windrunner",RANGE,
						1,1,1,1,0,1 };
	hero wyvern = { true,"Winter Wyvern",117,"npc_dota_hero_winter_wyvern",RANGE,
						0,3,1,2 };
	hero witch_doctor = { true,"Witch Doctor",118,"npc_dota_hero_witch_doctor",RANGE,
						0,3,2,1 };
	hero wraith_king = { true,"Wraith King",119,"npc_dota_hero_skeleton_king",MELEE,
						2,1,0,2,3,1 };
	hero zeus = { true,"Zeus",120,"npc_dota_hero_zuus",RANGE,
						1,0,3 };


hero heropool[poolSize] = { abaddon,alchemist,ancient_app,antimage,arc,axe,bane,batrider,
				beastmaster,bloodseeker,bountyhunter,brewmaster,bristeback,broodmother,
				centaur,chaos,chen,clinkz,clockwerk,maiden,darkseer,willow,dawnbreaker,
				dazzle,death_prophet,disruptor,doom,dragon,drow,earth_spirit,earthshaker,
				elder,ember,enchantress,enigma,face_void,grimsptoke,gyrocopter,hoodwink,huskar,
				invoker,io,jakiro,juggernaut,kotl,kunkka,legion,leshrac,lich,lifestealer,lina,lion,
				lone_druid,luna,lycan,magnus,mars,medusa,meepo,mirana,monkey,morphling,naga,nature_prophet,
				necrophos,stalker,nyx,ogre,omniknight,oracle,obsidian,pangolier,phantom_assasin,phantom_lancer,
				phoenix,puck,pudge,pugna,qop,razor,riki,rubick,sand_king,shadow_demon,shadow_fiend,shadow_shaman,
				silenser,skywrath,slardar,slark,snapfire,sniper,spectre,spirit_breaker,storm,sven,techies,templar,
				terrorblade,tidehunter,timbersaw,tinker,tiny,treant,troll,tusk,underlord,undying,ursa,vengeful,
				venomancer,viper,visage,void_spirit,warlock,weaver,windranger,wyvern,witch_doctor,wraith_king,zeus };







