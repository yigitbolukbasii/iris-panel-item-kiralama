quest rent_item begin
	state start begin
		when login begin
			cmdchat("rent_item_q "..q.getcurrentquestindex())
		end
		when button or info begin
			say_title("Ekipman Kiralama")
			say("")
			say_reward("Ne yapmak istiyorsun ?")
			local s = select("Ekipman Geri Al","Bekleyen Ekipmanlar","Vazge�	")
			if s == 1 then
				command("get_rent_items")
			elseif s == 2 then
				say_title("Ekipman Kiralama")
				say("")
				say("E�er oyuncu oyundan ��km�� ise kiralanan ekipmanlar")
				say("Bekleyen ekipmanlara d��er.")
				say("Bu i�lemi ger�ekle�tirdi�inizde ekipman� geri alabilirsiniz.")
				wait()
				local ret = pc.delete_rent_items()
				if ret == 0 then
					say_title("Ekipman Kiralama")
					say("")
					say_reward("Bekleyen bir ekipman mevcut de�il.")
					return
				elseif ret == 1 then
					say_title("Ekipman Kiralama")
					say("")
					say_reward("Ekipmanlar�n nesne market deposuna g�nderildi.")
					return
				elseif ret == 2 then
					say_title("Ekipman Kiralama")
					say("")
					say_reward("Ekipmanlar�n hen�z s�resi dolmam��.")
					return
				end
			elseif s == 3 then
			end
		end
	end
end