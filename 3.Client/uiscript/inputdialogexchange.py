import uiScriptLocale
import localeInfo
window = {
	"name" : "InputDialogExchange",

	"x" : 0,
	"y" : 0,

	"style" : ("movable", "float",),

	"width" : 350,
	"height" : 278,

	"children" :
	(
		{
			"name" : "board",
			"type" : "board_with_titlebar",

			"x" : 0,
			"y" : 0,

			"width" : 350,
			"height" : 278,

			"title" : "",

			"children" :
			(
				{
					"name" : "BarPanel",
					"type" : "text",

					"x" : 140,
					"y" : 186,

					"text" : localeInfo.EXCHANGE_TIME_0,
				},
				# Yazilar
				{
					"name" : "yazilar",
					"type" : "thinboard",

					"x" : 2,
					"y" : 36,
					"width" : 320,
					"height" : 127,
					"horizontal_align" : "center",

					"children" :
					(
					
						# User Name
						{
							"name" : "UserName",
							"type" : "text",
							
							"x" : 10,
							"y" : 7,
							
							"text" : uiScriptLocale.EXCHANGE_RENT_INFO_0,
						},
						
						{
							"name" : "yazi3",
							"type" : "text",
							
							"x" : 10,
							"y" : 27,
							
							"text" : uiScriptLocale.EXCHANGE_RENT_INFO_1,
						},
						
						{
							"name" : "yazi1",
							"type" : "text",
							
							"x" : 10,
							"y" : 47,
							
							"text" : uiScriptLocale.EXCHANGE_RENT_INFO_2,
						},
						
						{
							"name" : "yazi2",
							"type" : "text",
							
							"x" : 10,
							"y" : 67,
							
							"text" : uiScriptLocale.EXCHANGE_RENT_INFO_3,
						},
						
						{
							"name" : "yazi4",
							"type" : "text",
							
							"x" : 10,
							"y" : 87,
							
							"text" : uiScriptLocale.EXCHANGE_RENT_INFO_4,
						},		
					),

				},

				## Button
				{
					"name" : "AcceptButton",
					"type" : "button",

					"x" : - 61 - 5 + 30,
					"y" : 238,
					"horizontal_align" : "center",

					"text" : uiScriptLocale.OK,

					"default_image" : "d:/ymir work/ui/public/middle_button_01.sub",
					"over_image" : "d:/ymir work/ui/public/middle_button_02.sub",
					"down_image" : "d:/ymir work/ui/public/middle_button_03.sub",
				},
				{
					"name" : "CancelButton",
					"type" : "button",

					"x" : 5 + 30,
					"y" : 238,
					"horizontal_align" : "center",

					"text" : uiScriptLocale.CANCEL,

					"default_image" : "d:/ymir work/ui/public/middle_button_01.sub",
					"over_image" : "d:/ymir work/ui/public/middle_button_02.sub",
					"down_image" : "d:/ymir work/ui/public/middle_button_03.sub",
				},
			),
		},
	),
}