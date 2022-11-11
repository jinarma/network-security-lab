def check_password(password: str):
	strength_indicators = {'special_chars':[0], 'uppercase':[0], 'lowercase':[0], 'number':[0]}
	special_char = list(range(32, 48))+list(range(58, 65))+list(range(91, 97))+list(range(123, 127))
	strength_indicators['special_chars'].append(special_char)
	uppercase = list(range(65, 91))
	strength_indicators['uppercase'].append(uppercase)
	lowercase = list(range(97, 123))
	strength_indicators['lowercase'].append(lowercase)
	number = list(range(48, 59))
	strength_indicators['number'].append(number)

	# print(special_char)
	for el in password:
		print(ord(el))
		try:
			if ord(el) in strength_indicators['special_chars'][1]:
				strength_indicators['special_chars'][0] += 1
			elif ord(el) in strength_indicators['uppercase'][1]:
				strength_indicators['uppercase'][0] += 1
			elif ord(el) in strength_indicators['lowercase'][1]:
				strength_indicators['lowercase'][0] += 1
			elif ord(el) in strength_indicators['number'][1]:
				strength_indicators['number'][0] += 1
		except:
			pass
	return strength_indicators
	pass


print(check_password('askjfbqk243rjn!'))