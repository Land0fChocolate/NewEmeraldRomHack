# Pokémon Emerald

This is a rom hack of Pokemon Emerald using pokeemerald-expansion as its base: https://github.com/rh-hideout/pokeemerald-expansion.

# TODO

- implement ability description label in the summary screen.
- Include ORAS dex Pokemon like Budew and Dusknoir and add ways to access them.
- New Pokemon moves.
	- animations for new moves
	- Add the new moves to the move tutors lists.
- Update move tutor lists to have tutor moves from later gens.
- Expand and add new areas, including adding some new wild Pokemon for the area.
- New NPCs, some of which you acquire new items from.
- Rework aspects of the Battle Frontier. Change the Battle Palace to be themed around inverse type matchups. Rework the battle Pokemon list. 
- Add methods to make training easier. Super vitamins (giving 60 EVs per stat), IV boosters and nature mints to be added and accessable.
- Revert some unnecessary changes Emerald made from Ruby/Sapphire like the Vigoroth movers and Zigzagoon attacking Prof Birch instead of Poochyena.
- Type resisting berries and Type boosting gems to be accessible somewhere. 
- Remove item use in battle and create a prompt for Poke Balls.
- Add credits of people whos tutorials and work you have used in the game.

# Changelog

- Many post gen 3 features from pokeemerald Expansion are in this ROM.
	- Including physical/special split, fairy types, new moves, new items, new Pokemon species, regional species variants.
	- Whilst data for all post gen3 Pokemon are in the game, only those that existed in gens 1-3 or have evolutions linked to Pokemon in those gens are accessible, baring a few exceptions (Namely Alolan Vulpix and evo).
- Pokemon can have up to 3 active abilities at once, dependant on their species.
	- Many Pokemon have had their ability sets updated with new abilities (TODO: make a list of ability stat changes somewhere).
- New moves and abilities (listed below).
- Some vanilla abilities have been updated to make them more useful and compatible with the new multi ability change (listed below).
- Many gameplay adjustments to vanilla moves (Listed below). 
	- Changes to level up and TM learnsets of some Pokemon (TODO: make list).
	- Pokemon will attempt to learn a new move upon evolution.
	- OHKO moves have been removed from battle facility movepools.
- Some Pokemon have base stat changes to better fit their theme and gameplay. Treecko line has its Attack and Special Attack swapped. (TODO: make list)
- HMs have been removed and Pokemon can use the HM field commands without needing to learn the move. Only the relevant badge and a compatible Pokemon species are required to traverse obstacles.
- Berry tree drop rates are tripled. Interaction with berry trees is also quicker.
- Number of Feebas spots is tripled.
- TMs have infinite use.
- TMs from #51 to #99 have been added. They are similar to the gen 7 TM set (TODO: make list).
- New shops and updates to existing shops to stock later gen items and new TMs.
- Ice types have their special defense boosted by 50% in hail.
- Removed badge boosts
- Wild Encounters adjusted.
- Trainer parties adjusted.
- Level up requirements of many Pokemon have been tweaked. Starters evolve a little later. Pokemon with unnecessarily late evolutions (like the fossils, Rufflet, Deino) evolve earlier (TODO: list them below).
- Steven is back to being champion and Wallace back to being a gym leader.
- Prof Birch is chased by a Poochyena instead of a Zigzagoon, just like in Ruby/Sapphire.
- Map changes, including new areas to explore that have new Pokemon.
- Graphical updates to overworld sprites and environments.
- Various story changes. Includes aspects from ORAS.

# New Abilities

- Volume Up: Power of sound based moves have increased by 33%. Used by Loudred/Exploud.
- Lava Body: Attackers who make contact will always get inflicted with burn unless they have immunity. Used by Slugma/Magargo.
- Wildfire: Sp.Atk raises one stage after fainting an opponent. Used by Quilava/Typlosion.
- Miracle Blossom: User and ally restore 1/8 HP at the end of every turn. Used by Bayleef/Meganium/Xerneas.
- Scorching Heart: Power of Fire type moves increased by 50%. Used by Solrock/Groudon/Solgaleo.
- Ice Affinity: Power of Ice type moves increased by 50%. Used by Lunatone/Kyogre/Piplup/Prinplup/Empoleon/Lunala.
- Aquatic: Power of Water type moves increased by 50%. Used by Anorith/Armaldo/Dhelmise/Clobbopus/Grapploct.
- Gardener: Power of Grass type moves increased by 50%. Used by Floette/Florges.
- Prickly Thorns: Effectively like Rough Skin. Used by Cacnea/Cacturne.
- Aura Sense: User shudders if opponent has super-effective move. Also ignores evasive boosts from target. Used by Riolu/Lucario.
- Soul Siphon: Contact from user steals 1/8 HP from target and heals for the same amount. Used by Duskull/Dusclops/Dusknoir/Palossand/Dhelmise/Corsola(Galarian).
- Bad Luck: Opponent cannot land crits and less likely to land status moves against user. Used by Spiritomb/Cofagrigus.
- Wickedness: User super-effective moves do 25% more damage. Used by Hitmonchan/Mismagius/Braixen/Delphox.
- Spinning Body: User's physical contact moves remove field hazards and raise speed one stage. Used by Pineco/Forretress/Hitmontop/Donphan/Klink/Klang/Kilinklang.
- Evergreen: User takes half damage from Ice type moves and is immune to hail. Used by Grotle/Torterra/Skiddo/Gogoat.
- Hematophagy: Healing effects from drain moves increased by 50%. Used by Zubat/Golbat/Crobat/Yveltal.
- Swordmaster: Power of sword/blade moves increased by 33% (Leaf Blade/X-Scissor/Sacred Sword/Razor Shell/Secret Sword/Solar Blade/Behemoth Blade). Used by Leafeon/Dewott/Samurott/Cobalion/Terrakion/Verizion/Keldeo/Fomantis/Lurantis/Zacian.
- Supercooled: User's Ice type moves are super-effective against Water types. Used by Lapras/Glaceon/Aurorus.
- Disarm: User's contact moves inflict the Embargo status (disable held items) on the target. Used by Meowth/Persian/Pawniard/Bisharp/Meowth(Galarian)
- King's Might: User doesn't need to recharge on moves like Hyper Beam and Giga Impact. Used by Slaking.
- Pleasant Dreams: Heals sleeping Pokemon 1/4 HP every turn. Used by Cresselia.
- Wish Maker: User creates a wish on entry. Used by Jirachi.
- Heart Swap: If user makes contact with target, stat changes are swapped. Used by Manaphy.

# Updated Abilities

- Trace: copies the opponent’s highest rated ability that the user doesn’t already have.
- Receiver: copies fainted ally’s strongest ability that the user doesn’t already have.
- Mummy: replaces all the contact attacker’s abilities with just the Mummy ability.
- Wandering Spirit: replaces each respective ability with the attacker if hit by a contact move unless it is a banned ability.
- Neutralizing Gas: Nullifies other Pokemon abilities unless it is a banned ability like Stance Change. User abilities still active.
- Shell Armor/Battle Armor: Also reduces damage of neutral effective moves by 25%.
- Sand Veil: Increases Sp.Def instead of evasion by one stage.
- Snow Cloak: Increases Defense instead of evasion by one stage.
- Slow Start: Timer tuned down to 1 turn from 5.
- Sweet Veil: Also ignores evasion boosts from target.
- Corrosion: Also makes user's poison moves super effective against steel types.
- Solar Power: No longer decreases HP. Power modifier changed to 25% from 50%.
- Normalize: Buffed to 30% from 20%.
- Liquid Voice: Also powers up sound moves by 20%.
- Cursed Body: Now always disables the move for just the next turn.
- Suction Cups: Also traps target when user strikes it with a contact move.
- Keen Eye: Also increases move accuracy by 30%.
- Illuminate: Also ignores opponent evasion boosts.
- Damp: Also grants user immunity to powder based moves and abilities.
- Multitype: Also includes Adaptability and Filter effects.
- Victory Star: User and ally accuracy set to 100%.
- Sturdy will not activate if the user has a max HP of 1.

# New Moves

- War Dance: User have their own attack and speed rise by 1 stage and attempts to confuse the opponent. Learned by Sentret/Furret/Yungoos/Gumshoos via level up.
- Flint Blade: 75 BP, 100% Acc, Rock type, increased crit ratio. Boosted by Swordmaster ability. Added to Battle Frontier move tutor list. Learned by Leafeon/Dewott/Samurott/Cobalion/Terrakion/Verizion/Keldeo/Fomantis/Lurantis/Zacian/Rockruff/Lycanroc/Gigalith/Onix/Steelix/Omanite/Omastar/Kabuto/Kabutops/Aerodactyl/Anorith/Armaldo/Shieldon/Bastiodon/Binacle/Barbaracle/Rhyhorn/Rhydon/Rhypherior/Aggron/Kleavor/Seviper.
- Flare Crash: 100 BP, 100% Acc, Fire type, reduces user's speed by one stage. Added to Battle Frontier move tutor list. Learned by Growlith/Arcanine/Ponyta/Rapidash/Flareon/Quilava/Typhlosion/Entei/Torkoal/Tepig/Pignite/Emboar/Heatmor/Litten/Torracat/Incineroar/Scorbunny/Raboot/Cinderace/Charmander/Charmeleon/Charizard/Combusken/Blaziken/Numel/Camerupt/Vulpix/Ninetales/Monferno/Infernape/Heatran/Litleo/Pyroar/Houndour/Houndoom/Carkoal/Coalossal/Groudon/Luxio/Luxray/Phanpy/Donphan/Absol/Skuntank/Zebstrika/Darmanitan/Solgaleo.
- Singularity: A protect move that lowers the speed of foes who make contact by one stage. Learned by Gardevoir on evolution.
- Serpent Dance: Increases the user's special attack and speed by one stage. Added to Battle Frontier move tutor list. Learned by Seviper/Milotic/Serperior/Dunsparce/Ekans/Arbok/Huntail/Gorebyss/Rayquaza/Silicobra/Sandaconda/Giratina/Gyarados/Furret.

# Updated Moves

- Simple Beam: Replaces opponents abilities with the Simple ability. If opponent has a banned ability such as Stance Change, then they will still keep that ability but the others will be replaced with Simple.
- Worry Seed: Replaces opponents abilities with just the Worry Seed ability. If opponent has a banned ability such as Stance Change, then they will still keep that ability but the others will be replaced with Worry Seed.
- Entrainment: Replaces opponents abilities with the user’s abilities. If opponent has a banned ability such as Stance Change, then they will still keep that ability but the others will be replaced with the user’s abilities in their respective slot.
- Skill Swap: swaps the user abilities with the target abilities.  If opponent has a banned ability such as Stance Change, then they will still keep that ability but the others will be replaced with the user’s abilities in their respective slot.
- Gastro Acid: Neutralises target abilities unless it is a banned ability like Stance Change.
- Role Play: replaces the user’s abilities with the target’s abilities.
- Core Enforcer: Nullifies opponent’s abilities.
- Charge Beam: Now 40 BP, 100% Acc with 100% chance for special attack boost.
- Rock Smash: Now 50 BP with 100% chance for target defense drop.
- Poison Fang: Now has a 100% chance to poison target.
- Cut: Now has 30 BP and always crits.

# Credits

The fine people who worked on pokeemerald and pokeemerald-expansion and helped me with problems:
- DizzyEggg
- LOuroboros/Lunos
- BuffelSaft
- Blackforest92
- ExpoSeed
- SBird1337
- aarant
- SonikkuA-DatH
- Xavion3
- GriffinR
- kleeenexfeu
- Citrus Bolt
- dunsparce9
- Sapphire Jester
- TheXaman
- MeekRhino