.PHONY: new

SEGMENT = segment$(ID)

new:
ifeq ($(ID),7)
	echo S$(ID)
	mkdir -p $(SEGMENT)
	sed 's/M1SA_F_Control_CS/M1SA_F_Control_S$(ID)/g' center/M1SA_F_Control_CS.h > $(SEGMENT)/M1SA_F_Control_S$(ID).h
	sed 's/M1SA_F_Control_CS/M1SA_F_Control_S$(ID)/g' center/M1SA_F_Control_CS_private.h > $(SEGMENT)/M1SA_F_Control_S$(ID)_private.h
	sed 's/M1SA_F_Control_CS/M1SA_F_Control_S$(ID)/g' center/M1SA_F_Control_CS_types.h > $(SEGMENT)/M1SA_F_Control_S$(ID)_types.h
	sed 's/M1SA_F_Control_CS/M1SA_F_Control_S$(ID)/g' center/rtwtypes.h > $(SEGMENT)/rtwtypes.h
	sed 's/M1SA_F_Control_CS/M1SA_F_Control_S$(ID)/g' center/M1SA_F_Control_CS.c > $(SEGMENT)/M1SA_F_Control_S$(ID).c
	sed 's/M1SA_F_Control_CS/M1SA_F_Control_S$(ID)/g' center/M1SA_F_Control_CS_data.c > $(SEGMENT)/M1SA_F_Control_S$(ID)_data.c
	echo 'use simulink_binder::import;\n\nimport!{M1SA_F_Control_S$(ID),\nr##"' > $(SEGMENT)/mod.rs
	cat $(SEGMENT)/M1SA_F_Control_S$(ID).h >> $(SEGMENT)/mod.rs
	echo '"##}' >> $(SEGMENT)/mod.rs
else
	echo S$(ID)
	mkdir -p $(SEGMENT)
	sed 's/M1SA_F_Control_OA/M1SA_F_Control_S$(ID)/g' outer/M1SA_F_Control_OA.h > $(SEGMENT)/M1SA_F_Control_S$(ID).h
	sed 's/M1SA_F_Control_OA/M1SA_F_Control_S$(ID)/g' outer/M1SA_F_Control_OA_private.h > $(SEGMENT)/M1SA_F_Control_S$(ID)_private.h
	sed 's/M1SA_F_Control_OA/M1SA_F_Control_S$(ID)/g' outer/M1SA_F_Control_OA_types.h > $(SEGMENT)/M1SA_F_Control_S$(ID)_types.h
	sed 's/M1SA_F_Control_OA/M1SA_F_Control_S$(ID)/g' outer/rtwtypes.h > $(SEGMENT)/rtwtypes.h
	sed 's/M1SA_F_Control_OA/M1SA_F_Control_S$(ID)/g' outer/M1SA_F_Control_OA.c > $(SEGMENT)/M1SA_F_Control_S$(ID).c
	sed 's/M1SA_F_Control_OA/M1SA_F_Control_S$(ID)/g' outer/M1SA_F_Control_OA_data.c > $(SEGMENT)/M1SA_F_Control_S$(ID)_data.c
	sed -i 's/OAseg_LC2CG/OAseg_LC2CG_S$(ID)/g' $(SEGMENT)/M1SA_F_Control_S$(ID).h
	sed -i 's/OAseg_LC2CG/OAseg_LC2CG_S$(ID)/g' $(SEGMENT)/M1SA_F_Control_S$(ID).c
	sed -i 's/OAseg_SA_dynDen/OAseg_SA_dynDen_S$(ID)/g' $(SEGMENT)/M1SA_F_Control_S$(ID).h
	sed -i 's/OAseg_SA_dynDen/OAseg_SA_dynDen_S$(ID)/g' $(SEGMENT)/M1SA_F_Control_S$(ID).c
	sed -i 's/OAseg_SA_dynNum/OAseg_SA_dynNum_S$(ID)/g' $(SEGMENT)/M1SA_F_Control_S$(ID).h
	sed -i 's/OAseg_SA_dynNum/OAseg_SA_dynNum_S$(ID)/g' $(SEGMENT)/M1SA_F_Control_S$(ID).c
	echo 'use simulink_binder::import;\n\nimport!{M1SA_F_Control_S$(ID),\nr##"' > $(SEGMENT)/mod.rs
	cat $(SEGMENT)/M1SA_F_Control_S$(ID).h >> $(SEGMENT)/mod.rs
	echo '"##}' >> $(SEGMENT)/mod.rs
endif
