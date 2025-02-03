/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/02/03 15:16:59 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *stack)
{
    t_node *tmp;

    tmp = stack->head;
    while (tmp)
    {
        printf("%d -> ", tmp->value);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

void print_rev(t_stack *stack)
{
    t_node *tmp;

    tmp = stack->last;
    while (tmp)
    {
        printf("%d -> ", tmp->value);
        tmp = tmp->prev;
    }
    printf("NULL\n");
}

bool	stack_is_not_sorted(t_node *ap)
{
	t_node	*current;
	t_node	*check;

	current = ap;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value > check->value)
				return (true);
			check = check->next;
		}
		current = current->next;
	}
	return (false);
}


int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	ft_memset(&stack_a, 0, sizeof(t_stack));
	ft_memset(&stack_b, 0, sizeof(t_stack));
	if (parsing(&stack_a, argc, argv) == 1)
	{
		free_stack(&stack_a);
		return (error());
	}
	if (stack_a.len == 2)
		sort_two(&stack_a);
	else if (stack_a.len == 3)
		sort_three(&stack_a);
	else if (stack_a.len > 3)
		sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
}


/*

./push_swap 265 132 370 288 389 356 136 5 1 158 347 40 199 87 436 466 454 233 435 46 499 116 155 266 18 350 463 440 169 74 315 379 22 352 252 88 455 419 25 197 439 118 407 165 259 312 52 191 425 35 175 392 332 44 476 81 181 249 106 221 338 216 213 109 297 7 477 93 344 254 308 140 256 361 228 258 465 472 70 459 157 469 366 48 250 403 134 271 186 494 283 416 357 215 382 303 20 150 444 261 298 71 220 203 333 85 384 278 406 391 405 378 342 218 418 152 239 404 474 172 479 468 450 483 112 59 51 8 414 178 402 482 489 470 386 446 60 280 230 246 53 260 268 267 428 38 282 348 387 262 492 330 204 380 331 462 453 417 3 376 66 336 329 135 408 478 305 189 302 430 291 39 137 272 438 355 299 33 209 103 125 424 23 151 145 154 328 99 41 248 373 153 15 65 401 104 485 399 9 341 141 381 171 461 115 277 432 289 497 170 119 369 413 212 423 37 270 12 144 89 374 422 395 255 80 318 101 196 284 287 56 100 129 304 433 110 27 174 290 114 294 55 76 98 19 206 148 388 323 490 173 383 412 317 124 324 437 105 452 194 207 21 257 73 61 222 16 486 138 187 188 128 320 156 30 411 279 57 456 142 219 311 390 182 200 293 420 415 316 442 113 269 195 17 131 301 231 75 397 354 362 43 97 368 307 161 464 365 32 495 36 286 126 4 147 385 108 426 274 364 244 62 123 127 276 102 69 296 120 377 77 162 64 208 84 498 367 34 346 201 67 275 337 309 285 427 149 54 164 217 321 42 95 245 210 92 295 458 91 184 235 481 339 247 360 429 192 398 2 193 190 460 90 471 10 225 300 445 14 202 86 243 409 351 394 310 410 242 180 96 473 334 163 314 224 226 447 227 50 139 11 281 484 111 340 232 198 273 159 421 179 319 358 431 238 237 24 441 78 82 31 363 167 449 496 313 493 393 211 107 68 58 253 371 160 487 480 306 13 343 234 349 121 229 177 143 166 451 475 263 49 83 223 353 292 241 28 264 133 434 400 63 183 457 26 335 146 396 130 236 79 122 185 72 326 117 45 325 47 168 448 251 322 488 240 6 205 94 443 359 176 214 375 500 467 345 327 372 491 29 | wc -l

*/