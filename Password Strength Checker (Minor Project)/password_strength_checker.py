# A PROGRAM TO CHECK THE STRENGTH OF A PASSWORD
"""
Created on 11-11-2022

by Shubhankar Sharma (https://github.com/jinarma)

Contributors:
	Ashwath Mahajan
	Ananya Sharma
	Fazilet Beg
	Suvrat Sharma
"""



def password_check_full(password):

	ttypes = 0
	calculations = 0

	password_hash = create_password_hashmap(password)
	for key in password_hash.keys():
		if password_hash[key][0] > 0:
			ttypes += len(password_hash[key][1])
	calculations = ttypes**len(password)
	if calculations < 1000:
		print(f'Maximum {calculations} calculations needed')
	elif calculations >= 10**3 and calculations < 10**6:
		print(f'Maximum {calculations/10**3}K calculations needed')
	elif calculations >= 10**6 and calculations < 10**9:
		print(f'Maximum {calculations/10**6}M calculations needed')
	elif calculations >= 10**9:
		print(f'Maximum {calculations/10**9}B calculations needed')
	return calculations
	

def create_password_hashmap(password):
	strength_indicators = {
		'special_chars': [0, list(range(32, 48))+list(range(58, 65))+list(range(91, 97))+list(range(123, 127))],
		'uppercase': [0, list(range(65, 91))],
		'lowercase':[0, list(range(97, 123))],
		'number':[0, list(range(48, 58))]
		}
	print(strength_indicators['lowercase'][1])
	print(len(strength_indicators['lowercase'][1]))
	for el in password:
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


if __name__ == '__main__':
	input_string = input('Enter your password: ')
	password_check_full(input_string)

