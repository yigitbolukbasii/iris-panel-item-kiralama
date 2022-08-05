quest rent_item begin
	state start begin
		when login begin
			cmdchat("rent_item_q "..q.getcurrentquestindex())
		end
		when button or info begin
			say_title("Ekipman Kiralama")
			say("")
			say_reward("Ne yapmak istiyorsun ?")
			local s = select("Ekipman Geri Al","Bekleyen Ekipmanlar","Vazgeç	")
			if s == 1 then
				command("get_rent_items")
			elseif s == 2 then
				say_title("Ekipman Kiralama")
				say("")
				say("Eðer oyuncu oyundan çýkmýþ ise kiralanan ekipmanlar")
				say("Bekleyen ekipmanlara düþer.")
				say("Bu iþlemi gerçekleþtirdiðinizde ekipmaný geri alabilirsiniz.")
				wait()
				local ret = pc.delete_rent_items()
				if ret == 0 then
					say_title("Ekipman Kiralama")
					say("")
					say_reward("Bekleyen bir ekipman mevcut deðil.")
					return
				elseif ret == 1 then
					say_title("Ekipman Kiralama")
					say("")
					say_reward("Ekipmanlarýn nesne market deposuna gönderildi.")
					return
				elseif ret == 2 then
					say_title("Ekipman Kiralama")
					say("")
					say_reward("Ekipmanlarýn henüz süresi dolmamýþ.")
					return
				end
			elseif s == 3 then
			end
		end
	end
end