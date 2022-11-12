# A PROGRAM TO CHECK THE STRENGTH OF A PASSWORD
"""
Created on 11-11-2022

by Shubhankar Sharma (https://github.com/jinarma)
"""

import copy



def password_strength_numerical(password):
	try:
		int(password)
	except ValueError:
		print('Not a number only password:', password)
		return False
	print(10**len(password), 'calculations required')
	return True

def password_strength_only_chars(password):
	password_hash = copy.copy(create_password_hashmap(password))
	try:
		if password_hash['uppercase'][0] + password_hash['lowercase'][0] == len(password):
			print('Password only contains alphabets:', password)
			return True
	except:
		return False

def create_password_hashmap(password: str):
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
			print('Something\'s up in create_password_hashmap function')
	
	return strength_indicators


# print(create_password_hashmap('askjfbqk243rjn!'))
password_strength_numerical('12345')